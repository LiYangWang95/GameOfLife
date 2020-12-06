package game;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Random;

public class GameOfLife {

    private final int cols;
    private final int rows;
    private final Cell[][] cells;

    public GameOfLife(int cols, int rows) {
        assert(cols > 0 && rows > 0);
        this.cols = cols;
        this.rows = rows;

        // Build game board
        cells = new Cell[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cells[i][j] = new Cell();
            }
        }
        connectNeighbors();
    }

    public int getCols() {
        return cols;
    }

    public int getRows() {
        return rows;
    }

    public State getState(int row, int col) {
        return cells[row][col].getState();
    }

    private void connectNeighbors() {
        ArrayList<Pair<Integer,Integer>> directionNeighbor = new ArrayList(8);
        directionNeighbor.add(new Pair(0, 1));
        directionNeighbor.add(new Pair(1, 1));
        directionNeighbor.add(new Pair(1, 0));
        directionNeighbor.add(new Pair(1, -1));
        directionNeighbor.add(new Pair(0, -1));
        directionNeighbor.add(new Pair(-1, -1));
        directionNeighbor.add(new Pair(-1, 0));
        directionNeighbor.add(new Pair(-1, 1));

        // Set neighbors for every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Collection<Cell> neighbors = new ArrayList<Cell>(8);
                for (int k = 0; k < 8; k++) {
                    int rowNeighbor = i + directionNeighbor.get(k).getKey();
                    int colNeighbor = j + directionNeighbor.get(k).getValue();
                    if (rowNeighbor >= 0 && rowNeighbor < rows && colNeighbor >= 0 && colNeighbor < cols) {
                        neighbors.add(cells[rowNeighbor][colNeighbor]);
                    }
                }
                cells[i][j].setNeighbors(neighbors);
            }
        }
    }

    public void reset() {
        // Set random state for every cell
        Random rand = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rand.nextBoolean()) {
                    cells[i][j].setInitialState(State.ALIVE);
                } else {
                    cells[i][j].setInitialState(State.DEAD);
                }
            }
        }
    }

    public void nextGeneration() {
        // Calculate next states
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cells[i][j].calculateNextState();
            }
        }
        // Update states
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cells[i][j].updateState();
            }
        }
    }
}
