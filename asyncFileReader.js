const fs = require('fs').promises;

// Asynchronous function to read a file using Promises and async/await
async function readFileAsync(filePath) {
  try {
    // Reading file asynchronously
    const data = await fs.readFile(filePath, 'utf-8');
    console.log('Node.js Content:', data);
  } catch (error) {
    // Handling errors
    console.error('Node.js Error:', error.message);
  }
}

// Calling the async function
readFileAsync('sample.txt');
