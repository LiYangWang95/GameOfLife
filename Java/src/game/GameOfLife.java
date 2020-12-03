package game;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Collection;

public class GameOfLife {

    private final int numOfCols;
    private final int numOfRows;
    private final Cell[][] cells;

    private long tickInterval = 1000;

    public GameOfLife(int numOfCols, int numOfRows) {
        this.numOfCols = numOfCols;
        this.numOfRows = numOfRows;

        // Build game board
        cells = new Cell[numOfRows][numOfCols];
        for (int i = 0; i < numOfRows; i++) {
            for (int j = 0; j < numOfCols; j++) {
                cells[i][j] = new Cell();
            }
        }
        connectNeighbors();
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

        // Set neighbors for all the cells
        for (int i = 0; i < numOfRows; i++) {
            for (int j = 0; j < numOfCols; j++) {
                Collection<Cell> neighbors = new ArrayList<Cell>(8);
                for (int k = 0; k < 8; k++) {
                    int rowNeighbor = i + directionNeighbor.get(k).getKey();
                    int colNeighbor = j + directionNeighbor.get(k).getValue();
                    if (rowNeighbor >= 0 && rowNeighbor < numOfRows && colNeighbor >= 0 && colNeighbor < numOfCols) {
                        neighbors.add(cells[rowNeighbor][colNeighbor]);
                    }
                }
                cells[i][j].setNeighbors(neighbors);
            }
        }
    }

    public void startGame() {
        // set state for every cell
        // if state is still SETUP (e.g. wasn't changed by GUI, set it to DEAD)

        // TODO: setup timer callback function to nextGeneration()
        // TODO: start timer
    }

    public void nextGeneration() {
        // Calculate next states
        for (int i = 0; i < numOfRows; i++) {
            for (int j = 0; j < numOfCols; j++) {
                cells[i][j].calculateNextState();
            }
        }
        // Update states
        for (int i = 0; i < numOfRows; i++) {
            for (int j = 0; j < numOfCols; j++) {
                cells[i][j].updateState();
            }
        }
    }
}
