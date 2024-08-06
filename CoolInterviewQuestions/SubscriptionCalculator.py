# ```
# Our company has started selling to larger customers, so we are creating subscription tiers with different feature sets to cater to our customers’ unique needs. We previously charged every customer a flat fee per month, but now we plan on charging for the number of users active on the customer's subscription plan. As a result, we're changing our billing system.

# We'd like you to implement a monthly_charge function to calculate the total monthly bill for a customer.

# Customers are billed based on their subscription tier. We charge them a prorated amount for the portion of the month each user’s subscription was active. For example, if a user was activated or deactivated part way through the month, then we charge them only for the days their subscription was active.

# We want to bill customers for all days users were active in the month (including any activation and deactivation dates, since the user had some access on those days).

# We do need to support historical calculations (previous dates)
# We only charge whole cents
# Notes
# Here’s an idea of how we might go about this:

# Calculate a daily rate for the subscription tier
# For each day of the month, identify which users had an active subscription on that day
# Multiply the number of active users for the day by the daily rate to calculate the total for the day
# Return the running total for the month at the end
# please be sure to take care of the date and time format in python
# ```

import datetime
import calendar


def monthly_charge(month, subscription, users):
    """Computes the monthly charge for a given subscription.

    @rtype: int
    @returns: the total monthly bill for the customer in cents, rounded
        to the nearest cent. For example, a bill of $20.00 should return 2000.
        If there are no active users or the subscription is None, returns 0.

    @type month: str
    @param month - Always present
        Has the following structure:
        "2022-04"  # April 2022 in YYYY-MM format

    @type subscription: dict
    @param subscription - May be None
        If present, has the following structure:
        {
          'id': 763,
          'customer_id': 328,
          'monthly_price_in_cents': 359  # price per active user per month
        }

    @type users: list
    @param users - May be empty, but not None
        Has the following structure:
        [
          {
            'id': 1,
            'name': "Employee #1",
            'customer_id': 1,
            'activated_on': datetime.date(2021, 11, 4),
            'deactivated_on': datetime.date(2022, 4, 10)
          },
          {
            'id': 2,
            'name': "Employee #2",
            'customer_id': 1,
            'activated_on': datetime.date(2021, 12, 4),
            'deactivated_on': None
          },
        ]
    """
    if not subscription:
        return 0

    # Parse the month
    year, month_num = map(int, month.split("-"))
    start_date = datetime.date(year, month_num, 1)
    end_date = last_day_of_month(start_date)

    # Calculate the daily rate
    monthly_price = subscription["monthly_price_in_cents"]
    daily_rate = (
        monthly_price / (end_date - start_date + datetime.timedelta(days=1)).days
    )

    total_charge = 0

    # Calculate the total charge for the month
    current_date = start_date
    while current_date <= end_date:
        active_users = 0

        for user in users:
            activated_on = user["activated_on"]
            deactivated_on = user["deactivated_on"]

            if activated_on <= current_date and (
                deactivated_on is None or deactivated_on >= current_date
            ):
                active_users += 1

        daily_charge = active_users * daily_rate
        total_charge += daily_charge

        current_date = next_day(current_date)

    return round(total_charge)


####################
# Helper functions #
####################


def first_day_of_month(date):
    """Returns the first day of the month for a given date."""
    return date.replace(day=1)


def last_day_of_month(date):
    """Returns the last day of the month for a given date."""
    last_day = calendar.monthrange(date.year, date.month)[1]
    return date.replace(day=last_day)


def next_day(date):
    """Returns the next day of a given date."""
    return date + datetime.timedelta(days=1)
