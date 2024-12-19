package app.com;

import java.util.List;
import java.util.stream.Collectors;

public class ysisAnalResult {

    private String modelVersion;
    private Metadata metadata;
    private ReadResult readResult;

    // Getters and Setters
    public String getModelVersion() {
        return modelVersion;
    }

    public void setModelVersion(String modelVersion) {
        this.modelVersion = modelVersion;
    }

    public Metadata getMetadata() {
        return metadata;
    }

    public void setMetadata(Metadata metadata) {
        this.metadata = metadata;
    }

    public ReadResult getReadResult() {
        return readResult;
    }

    public void setReadResult(ReadResult readResult) {
        this.readResult = readResult;
    }

    // Metadata class
    public static class Metadata {
        private int width;
        private int height;

        // Getters and Setters
        public int getWidth() {
            return width;
        }

        public void setWidth(int width) {
            this.width = width;
        }

        public int getHeight() {
            return height;
        }

        public void setHeight(int height) {
            this.height = height;
        }
    }

    // ReadResult class
    public static class ReadResult {
        private List<Block> blocks;

        // Getters and Setters
        public List<Block> getBlocks() {
            return blocks;
        }

        public void setBlocks(List<Block> blocks) {
            this.blocks = blocks;
        }
    }

    // Block class
    public static class Block {
        private List<Line> lines;

        // Getters and Setters
        public List<Line> getLines() {
            return lines;
        }

        public void setLines(List<Line> lines) {
            this.lines = lines;
        }
    }

    // Line class
    public static class Line {
        private String text;
        private List<Point> boundingPolygon;
        private List<Word> words;

        // Getters and Setters
        public String getText() {
            return text;
        }

        public void setText(String text) {
            this.text = text;
        }

        public List<Point> getBoundingPolygon() {
            return boundingPolygon;
        }

        public void setBoundingPolygon(List<Point> boundingPolygon) {
            this.boundingPolygon = boundingPolygon;
        }

        public List<Word> getWords() {
            return words;
        }

        public void setWords(List<Word> words) {
            this.words = words;
        }
    }

    // Word class
    public static class Word {
        private String text;
        private List<Point> boundingPolygon;
        private double confidence;

        // Getters and Setters
        public String getText() {
            return text;
        }

        public void setText(String text) {
            this.text = text;
        }

        public List<Point> getBoundingPolygon() {
            return boundingPolygon;
        }

        public void setBoundingPolygon(List<Point> boundingPolygon) {
            this.boundingPolygon = boundingPolygon;
        }

        public double getConfidence() {
            return confidence;
        }

        public void setConfidence(double confidence) {
            this.confidence = confidence;
        }
    }

    // Point class
    public static class Point {
        private int x;
        private int y;

        // Getters and Setters
        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }
    }

     public String formatToSingleWord() {
        if (readResult == null || readResult.getBlocks() == null) {
            return "Nenhum bloco encontrado.";
        }

        StringBuilder formattedText = new StringBuilder();

        int blockIndex = 1;
        for (Block block : readResult.getBlocks()) {
            if (block.getLines() == null) {
                formattedText.append("Bloco ").append(blockIndex).append(": Nenhuma linha encontrada.\n");
                blockIndex++;
                continue;
            }

            String concatenatedWords = block.getLines().stream()
                .flatMap(line -> line.getWords().stream())
                .map(Word::getText)
                .collect(Collectors.joining(" "));

            formattedText.append("Bloco ").append(blockIndex).append(": ")
                         .append(concatenatedWords).append("\n");

            blockIndex++;
        }

        return formattedText.toString();
    }
}
