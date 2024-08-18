//IN SERIES Functions will be executed in a strict sequential order
const operations = [
  { func: function1, args: args1 },
  { func: function2, args: args2 },
  { func: function3, args: args3 },
];

function executeFunctionWithArgs(operation, callback) {
  // executes function
  const { args, func } = operation;
  func(args, callback);
}

function serialProcedure(operation) {
  if (!operation) ProcessingInstruction.exit(0);
  executeFunctionWithArgs(operation, function (result) {
    serialProcedure(operations.shift());
  });
}

serialProcedure(operations.shift());

// Full parallel: when ordering is not an issue, such as emailing a list of 1,000,000 email recipients.
let count = 0;
let success = 0;
const failed = [];
const recipients = [
  { name: "Bart", email: "bart@tld" },
  { name: "Marge", email: "marge@tld" },
  { name: "Homer", email: "homer@tld" },
  { name: "Lisa", email: "lisa@tld" },
  { name: "Maggie", email: "maggie@tld" },
];

function dispatch(recipient, callback) {
  // `sendEmail` is a hypothetical SMTP client
  sendMail(
    {
      subject: "Dinner tonight",
      message: "We have lots of cabbage on the plate. You coming?",
      smtp: recipient.email,
    },
    callback
  );
}

function final(result) {
  console.log(`Result: ${result.count} attempts \
      & ${result.success} succeeded emails`);
  if (result.failed.length)
    console.log(`Failed to send to: \
        \n${result.failed.join("\n")}\n`);
}

recipients.forEach(function (recipient) {
  dispatch(recipient, function (err) {
    if (!err) {
      success += 1;
    } else {
      failed.push(recipient.name);
    }
    count += 1;

    if (count === recipients.length) {
      final({
        count,
        success,
        failed,
      });
    }
  });
});

//Limited parallel: parallel with limit, such as successfully emailing 1,000,000 recipients from a list of 10E7 users.
let successCount = 0;

function final() {
  console.log(`dispatched ${successCount} emails`);
  console.log("finished");
}

function dispatch(recipient, callback) {
  // `sendEmail` is a hypothetical SMTP client
  sendMail(
    {
      subject: "Dinner tonight",
      message: "We have lots of cabbage on the plate. You coming?",
      smtp: recipient.email,
    },
    callback
  );
}

function sendOneMillionEmailsOnly() {
  getListOfTenMillionGreatEmails(function (err, bigList) {
    if (err) throw err;

    function serial(recipient) {
      if (!recipient || successCount >= 1000000) return final();
      dispatch(recipient, function (_err) {
        if (!_err) successCount += 1;
        serial(bigList.pop());
      });
    }

    serial(bigList.pop());
  });
}

sendOneMillionEmailsOnly();
