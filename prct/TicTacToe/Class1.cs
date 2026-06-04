using System;
using Gtk;

namespace TicTacToe
{
    public class MainWindow : Window
    {
        private string curSign;
        private int moveNum;
        private bool gameEnded;

        private Button[] cells = new Button[9];
        private Entry infoEntry;
        private Button restartButton;

        public MainWindow(Gtk.Application app) : base("Крестики-нолики")
        {
            this.Application = app;
            SetDefaultSize(400, 450);
            SetPosition(WindowPosition.Center);
            DeleteEvent += OnDeleteEvent;

            curSign = "X";
            moveNum = 1;
            gameEnded = false;

            BuildInterface();
        }

        private void BuildInterface()
        {
            VBox vbox = new VBox(false, 5);
            vbox.BorderWidth = 10;

            Grid grid = new Grid();
            grid.RowHomogeneous = true;
            grid.ColumnHomogeneous = true;

            for (int i = 0; i < 9; i++)
            {
                Button btn = new Button();
                Label lbl = new Label();
                lbl.Text = "";
                btn.Add(lbl);
                btn.Name = "cell" + (i + 1);
                btn.Clicked += OnCellClicked;
                grid.Attach(btn, i % 3, i / 3, 1, 1);
                cells[i] = btn;
            }
            vbox.PackStart(grid, true, true, 0);
            infoEntry = new Entry();
            infoEntry.Text = "Игра началась!";
            infoEntry.IsEditable = false;
            infoEntry.CanFocus = false;
            vbox.PackStart(infoEntry, false, false, 5);
            restartButton = new Button();
            restartButton.Label = "Начать заново";
            restartButton.Clicked += OnRestartClicked;
            vbox.PackStart(restartButton, false, false, 5);
            Add(vbox);
        }

        private void OnCellClicked(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            Label lbl = (Label)button.Child;
            if (string.IsNullOrEmpty(lbl.Text) && !gameEnded)
            {
                lbl.Text = curSign;
                if (CheckWin())
                {
                    gameEnded = true;
                    infoEntry.Text = $"Ход {moveNum}: Победил {curSign}!";
                }
                else if (CheckDraw())
                {
                    gameEnded = true;
                    infoEntry.Text = $"Ход {moveNum}: Ничья!";
                }
                else
                {
                    string cellNum = button.Name.Substring(4);
                    infoEntry.Text = $"Ход {moveNum}: {curSign} сходил на {cellNum} клетку";
                    curSign = (curSign == "X") ? "O" : "X";
                    moveNum++;
                }
            }
        }
        private bool CheckWin()
        {
            int[,] patterns = new int[,]
            {
                {0,1,2}, {3,4,5}, {6,7,8},
                {0,3,6}, {1,4,7}, {2,5,8},
                {0,4,8}, {2,4,6}
            };

            for (int i = 0; i < 8; i++)
            {
                Label a = (Label)cells[patterns[i, 0]].Child;
                Label b = (Label)cells[patterns[i, 1]].Child;
                Label c = (Label)cells[patterns[i, 2]].Child;

                if (!string.IsNullOrEmpty(a.Text) && a.Text == b.Text && b.Text == c.Text)
                    return true;
            }
            return false;
        }
        private bool CheckDraw()
        {
            foreach (Button cell in cells)
            {
                Label lbl = (Label)cell.Child;
                if (string.IsNullOrEmpty(lbl.Text))
                    return false;
            }
            return true;
        }
        private void OnRestartClicked(object sender, EventArgs e)
        {
            curSign = "X";
            moveNum = 1;
            gameEnded = false;

            foreach (Button cell in cells)
            {
                Label lbl = (Label)cell.Child;
                lbl.Text = "";
            }

            infoEntry.Text = "Игра началась!";
        }
        private void OnDeleteEvent(object sender, DeleteEventArgs a)
        {
            Gtk.Application.Quit();
        }
    }
}