const downloadFile = (url) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(url);
    }, 1000);
  });
};

const downloadInBatches = async (urls, batchSize) => {
  for (let i = 0; i < urls.length; i += batchSize) {
    const batch = urls.slice(i, i + batchSize);
    await Promise.allSettled(batch.map((url) => downloadFile(url)));
  }
};

const urls = ["50urls"];
downloadInBatches(urls, 5);
