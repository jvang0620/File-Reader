import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.concurrent.CompletableFuture;

public class asyncFileReader {

    public static void main(String[] args) {
        String filePath = "sample.txt";

        // Using CompletableFuture for asynchronous execution
        CompletableFuture.supplyAsync(() -> readFileAsync(filePath))
                // Handling successful completion
                .thenAccept(data -> System.out.println("Java Content: " + data))
                // Handling errors
                .exceptionally(error -> {
                    System.err.println("Java Error: " + error.getMessage());
                    return null;
                });
    }

    // Asynchronous file reading method
    static String readFileAsync(String filePath) {
        try {
            // Reading file asynchronously
            byte[] data = Files.readAllBytes(Paths.get(filePath));
            return new String(data);
        } catch (Exception e) {
            // Throwing a runtime exception for error handling
            throw new RuntimeException(e.getMessage());
        }
    }
}
