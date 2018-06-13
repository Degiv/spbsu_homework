package com.group144.degiv;


import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ChoiceBox;
import javafx.scene.text.Text;

public class Controller {

    @FXML
    public Text firstOperand;

    @FXML
    public Text secondOperand;

    @FXML
    public Text result;

    @FXML
    ChoiceBox operator = new ChoiceBox();

    @FXML
    /**
     * initializes working variables
     */
    public void initialize() {
        firstOperand.setText("0");
        secondOperand.setText("0");
        result.setText("0");

        operator.getItems().addAll("+","-","*","/");
        operator.setValue("+");
    }

    /**
     * calculates current expression
     */
    public void calculate() {
        int intFirstOperand = Integer.parseInt(firstOperand.getText());
        int intSecondOperand = Integer.parseInt(secondOperand.getText());

        int intResult = 0;
        switch (String.valueOf(operator.getValue())) {
            case "+":
                intResult = intFirstOperand + intSecondOperand;
                break;

            case "-":
                intResult = intFirstOperand - intSecondOperand;
                break;

            case "*":
                intResult = intFirstOperand * intSecondOperand;
                break;

            case "/":
                intResult = intFirstOperand / intSecondOperand;
                break;
        }
        result.setText(String.valueOf(intResult));
    }

    /**
     * methods for actions
     * @param actionEvent action
     */
    public void incrementFirstAction(ActionEvent actionEvent) {
        int operand = Integer.parseInt(firstOperand.getText());
        operand++;
        firstOperand.setText(String.valueOf(operand));
        calculate();
    }

    public void decrementFirstAction(ActionEvent actionEvent) {
        int operand = Integer.parseInt(firstOperand.getText());
        operand--;
        firstOperand.setText(String.valueOf(operand));
        calculate();
    }

    public void incrementSecondAction(ActionEvent actionEvent) {
        int operand = Integer.parseInt(secondOperand.getText());
        operand++;
        secondOperand.setText(String.valueOf(operand));
        calculate();
    }

    public void decrementSecondAction(ActionEvent actionEvent) {
        int operand = Integer.parseInt(secondOperand.getText());
        operand--;
        secondOperand.setText(String.valueOf(operand));
        calculate();
    }

}