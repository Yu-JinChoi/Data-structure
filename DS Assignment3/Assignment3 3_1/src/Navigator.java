import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLayeredPane;
import javax.swing.JEditorPane;
import javax.swing.JButton;

public class Navigator extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Navigator frame = new Navigator();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Navigator() {
		setTitle("Navigator");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 756, 523);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JLayeredPane layeredPane = new JLayeredPane();
		contentPane.add(layeredPane, BorderLayout.CENTER);
		
		JEditorPane editorPane = new JEditorPane();
		editorPane.setBounds(12, 10, 525, 454);
		layeredPane.add(editorPane);
		
		JButton btnNewButton = new JButton("Generate Random Road");
		btnNewButton.setBounds(549, 45, 169, 34);
		layeredPane.add(btnNewButton);
		
		JButton btnFindShortestPath = new JButton("Find Shortest Path");
		btnFindShortestPath.setBounds(549, 139, 169, 34);
		layeredPane.add(btnFindShortestPath);
		
		JButton btnGetMst = new JButton("Get MST");
		btnGetMst.setBounds(549, 237, 169, 34);
		layeredPane.add(btnGetMst);
	}
}
