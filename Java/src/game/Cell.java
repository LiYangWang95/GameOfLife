package game;

import java.util.Collection;

public class Cell {
    private State state = State.SETUP;
    private Collection<Cell> neighbors;

    public void setNeighbors(Collection<Cell> neighbors) {
        this.neighbors = neighbors;
    }

    public void setInitialState(State state) {
        assert(state == State.ALIVE || state == State.DEAD);
        this.state = state;
    }

    public State getState() {
        return state;
    }

    private int getAliveNeighbors() {
        int count = 0;
        for (Cell neighbor: neighbors) {
            State state = neighbor.getState();
            if (state == State.ALIVE || state == State.WILLBEDEAD) {
                count++;
            }
        }
        return count;
    }

    public void calculateNextState() {
        int aliveNeighbors = getAliveNeighbors();
        if (state == State.ALIVE) {
            if (aliveNeighbors != 2 && aliveNeighbors != 3) {
                state = State.WILLBEDEAD;
            }
        } else if (state == State.DEAD) {
            if (aliveNeighbors == 3) {
                state = State.WILLBEALIVE;
            }
        }
    }

    public void updateState() {
        if (state == State.WILLBEALIVE) {
            state = State.ALIVE;
        } else if (state == State.WILLBEDEAD) {
            state = State.DEAD;
        }
    }
}
