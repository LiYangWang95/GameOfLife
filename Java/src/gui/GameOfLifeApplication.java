package gui;

import game.GameOfLife;
import game.State;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.concurrent.TimeUnit;


public class GameOfLifeApplication extends Application {

    private static final int width = 500;
    private static final int height = 500;
    private static final int cellSize = 10;

    private static final long timerInterval = 500;

    private static final Color aliveColor = Color.web("#2B2B2B");
    private static final Color deadColor = Color.web("#FFFFFF");

    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox(10);
        Scene scene = new Scene(root, width, height + 50);
        final Canvas canvas = new Canvas(width, height);

        Button reset = new Button("Reset");
        Button step = new Button("Step");
        Button run = new Button("Run");
        Button stop = new Button("Stop");

        root.getChildren().addAll(canvas, new HBox(10, reset, step, run, stop));
        primaryStage.setTitle("Game of Life");
        primaryStage.setScene(scene);
        primaryStage.show();

        int rows = (int) Math.floor((float) (height / cellSize));
        int cols = (int) Math.floor((float) (width / cellSize));

        GraphicsContext graphics = canvas.getGraphicsContext2D();

        GameOfLife game = new GameOfLife(rows, cols);
        game.reset();
        draw(game, graphics);

        AnimationTimer runAnimation = new AnimationTimer() {
            private long lastUpdate = 0;
            @Override
            public void handle(long now) {
                if ((now - lastUpdate) >= TimeUnit.MILLISECONDS.toNanos(timerInterval)) {
                    game.nextGeneration();
                    draw(game, graphics);
                    lastUpdate = now;
                }
            }
        };

        reset.setOnAction(l -> {
            game.reset();
            draw(game, graphics);
        });
        run.setOnAction( l -> runAnimation.start());
        step.setOnAction( l -> {
            game.nextGeneration();
            draw(game, graphics);
        });
        stop.setOnAction( l -> runAnimation.stop());
    }

    private void draw(GameOfLife game, GraphicsContext graphics) {
        // Clear graphics
        graphics.setFill(deadColor);
        graphics.fillRect(0, 0, width, height);

        // Draw game
        for (int i = 0; i < game.getRows(); i++) {
            for (int j = 0; j < game.getCols(); j++) {
                Color color = game.getState(i, j) == State.ALIVE ? aliveColor : deadColor;
                graphics.setFill(Color.gray(0.5, 0.5));
                graphics.fillRect(i * cellSize, j * cellSize, cellSize, cellSize);
                graphics.setFill(color);
                graphics.fillRect((i * cellSize) + 1, (j * cellSize) + 1, cellSize - 2, cellSize - 2);
            }
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
