using System;
using Gtk;

namespace TicTacToe
{
    class Program
    {
        class TicTacToeApp : Gtk.Application
        {
            protected override void OnActivated()
            {
                MainWindow win = new MainWindow(this);
                AddWindow(win);
                win.ShowAll();
            }
            public TicTacToeApp() : base("org.gtksharp.tictactoe", GLib.ApplicationFlags.None)
            {
            }
        }

        static void Main(string[] args)
        {
            GLib.Application app = new TicTacToeApp();
            app.Run();
        }
    }
}