#include "ground.h"
extern BGround_ BGround;
//************************************************************
//	this function will be called approximately 50 times a second
//
//	input_info:
//	contains the info wehre the mouse is and what keys or button are pressed
//	for the definition, right click on "input" in the argument list and click "go to definition"
//
//	draw_text ( CHARACTERARRAY, X-COORDINATE, Y-COORDINATE, RED,GREEN, BLUE); //color values between 0 and 255!
//
//	draw_line ( FROM X-COORDINATE, FROM Y-COORDINATE, TO X-COORDINATE, TO Y-COORDINATE, RED,GREEN, BLUE, WIDTH); //color values between 0 and 255! WIDTH .. in pixel
//
//	draw_pixel( X-COORDINATE, Y-COORDINATE, RED, GREEN, BLUE, PERMANENT);//color values between 0 and 255! PERMANENT: 0..temporary, 1..permanent
//
//**********************************************************

#define title 0
#define gameplay 1
#define restart 2
void pacman(int x, int y,int direction)
{
	static int rot = 0;
	if (direction == 2)
		rot = 1;
	if (direction == 1)
		rot = 0;
BGround.set_sprite_position(5, x, y, rot); //first argument 0 .. pacman picture
			
}

void draw_main(input input_info)
{
	static int status = title;


	if (status == title)
	{

		static int init = 1;
		static int field[17][17];
		for (int xx = 4; xx < 12; xx++)
			field[xx][5] = 1;
		for (int yy = 5; yy < 9; yy++)
			field[4][yy] = 1;
		for (int xx = 4; xx < 12; xx++)
			field[xx][8] = 1;
		for (int yy = 5; yy < 9; yy++)
			field[11][yy] = 1;
		for (int xx = 3; xx < 14; xx++)
			field[xx][3] = 1;
		for (int yy = 3; yy < 11; yy++)
			field[3][yy] = 1;
		for (int xx = 3; xx < 14; xx++)
			field[xx][10] = 1;
		//for (int yy=)

		BGround.set_sprite_position(6, 0, 0);

		if (input_info.l_button_down && (input_info.x_mouse >= 0 && input_info.x_mouse <= 500))
		{
			if (input_info.l_button_down && (input_info.y_mouse >= 200 && input_info.y_mouse <= 340))
			{
				status = gameplay;
			}

		}
	}





	//////////////////////////////////////////////////////////////////////////////////////////
	// Game Start 
	if (status == gameplay)
	{
		BGround.set_sprite_position(6, 700, 700);
		static int init = 1;
		static int field[17][17];
		if (init == 1)
		{
			init = 0;
			for (int xx = 0; xx < 17; xx++)
			{
				for (int yy = 0; yy < 17; yy++)
					field[xx][yy] = -1;
			}
		}
		float l = 30;
		for (int xx = 0; xx < 17; xx++)
		{
			for (int yy = 0; yy < 16; yy++)
			{

				if (field[xx][yy] == -1)
				{
					draw_pixel(((xx + 1) * l - 14), ((yy + 1) * l - 14), 200, 300, 250, 0);
					draw_pixel(((xx + 1) * l - 13), ((yy + 1) * l - 14), 200, 300, 250, 0);
					draw_pixel(((xx + 1) * l - 13), ((yy + 1) * l - 13), 200, 300, 250, 0);
					draw_pixel(((xx + 1)* l - 14), ((yy + 1) * l - 13), 200, 300, 250, 0);
				}
			}
		}




		for (int xx = 0; xx < 17; xx++)
			field[xx][0] = 1;
		for (int yy = 0; yy < 17; yy++)
			field[0][yy] = 1;
		for (int xx = 0; xx < 17; xx++)
			field[xx][16] = 1;
		for (int yy = 0; yy < 17; yy++)
			field[16][yy] = 1;
		for (int xx = 0; xx < 17; xx++)
			field[xx][17] = 1;
		for (int xx = 0; xx < 17; xx++)
			field[xx][15] = 1;
		for (int yy = 0; yy < 17; yy++)
			field[17][yy] = 1;


		field[4][1] = 1;
		field[12][1] = 1;
		field[2][2] = 1;
		field[4][2] = 1;
		field[6][2] = 1;
		field[7][2] = 1;
		field[8][2] = 1;
		field[9][2] = 1;
		field[10][2] = 1;
		field[12][2] = 1;
		field[14][2] = 1;
		field[8][3] = 1;
		field[2][4] = 1;
		field[3][4] = 1;
		field[4][4] = 1;
		field[5][4] = 1;
		field[8][4] = 1;
		field[11][4] = 1;
		field[12][4] = 1;
		field[13][4] = 1;
		field[14][4] = 1;
		field[2][5] = 1;
		field[14][5] = 1;
		field[2][6] = 1;
		field[4][6] = 1;
		field[5][6] = 1;
		field[11][6] = 1;
		field[12][6] = 1;
		field[14][6] = 1;
		field[5][7] = 1;
		field[7][7] = 1;
		field[8][7] = 1;
		field[9][7] = 1;
		field[11][7] = 1;
		field[1][8] = 1;
		field[2][8] = 1;
		field[5][8] = 1;
		field[7][8] = 1;
		field[8][8] = 1;
		field[9][8] = 1;
		field[11][8] = 1;
		field[14][8] = 1;
		field[15][8] = 1;
		field[3][10] = 1;
		field[4][10] = 1;
		field[5][10] = 1;
		field[7][10] = 1;
		field[8][10] = 1;
		field[9][10] = 1;
		field[11][10] = 1;
		field[12][10] = 1;
		field[13][10] = 1;
		field[5][11] = 1;
		field[8][11] = 1;
		field[11][11] = 1;
		field[3][12] = 1;
		field[5][12] = 1;
		field[8][12] = 1;
		field[11][12] = 1;
		field[13][12] = 1;
		field[3][13] = 1;
		field[13][13] = 1;
		field[2][14] = 1;
		field[3][14] = 1;
		field[4][14] = 1;
		field[7][14] = 1;
		field[8][14] = 1;
		field[9][14] = 1;
		field[12][14] = 1;
		field[13][14] = 1;
		field[14][14] = 1;
		///////////////////////////////
		// Makes the board
		int a[500][500];
		for (int xx = 0; xx < 500; xx++)
		{
			for (int yy = 0; yy < 500; yy++)
				a[xx][yy] = 0;
		}
		////////////////////////////////
		static int pacman_x = 100, pacman_y = 250;
		static int ghost_x = 40, ghost_y = 40, ghost_x2 = 200, ghost_y2 = 40, ghost_x3 = 300, ghost_y3 = 40, ghost_x4 = 100, ghost_y4 = 100;

		if (input_info.a_key_down == 1)
			pacman_x--;
		if (input_info.d_key_down == 1)
			pacman_x++;
		if (input_info.w_key_down == 1)
			pacman_y--;
		if (input_info.s_key_down == 1)
			pacman_y++;

		int npac_x = pacman_x, npac_y = pacman_y;
		int nghost_x = ghost_x, nghost_y = ghost_y;
		int nghost_x2 = ghost_x2, nghost_y2 = ghost_y2;
		int nghost_x3 = ghost_x3, nghost_y3 = ghost_y3;
		int nghost_x4 = ghost_x4, nghost_y4 = ghost_y4;
		//pacman borders
		/*if (npac_x < 0) npac_x = 0;
		if (npac_y < 0) npac_y = 0;

		if (a[npac_x][npac_y] == 0)
		{
		pacman_x = npac_x;
		pacman_y = npac_y;
		}*/
		//ghost borders

		if (nghost_x < 0) nghost_x = 0;
		if (nghost_y < 0) nghost_y = 0;


		if (a[nghost_x][nghost_y] == 0)
		{
			ghost_x = nghost_x;
			ghost_y = nghost_y;
		}
		if (nghost_x2 < 0) nghost_x2 = 0;
		if (nghost_y2 < 0) nghost_y2 = 0;


		if (a[nghost_x2][nghost_y2] == 0)
		{
			ghost_x2 = nghost_x2;
			ghost_y2 = nghost_y2;
		}
		if (nghost_x3 < 0) nghost_x3 = 0;
		if (nghost_y3 < 0) nghost_y3 = 0;


		if (a[nghost_x3][nghost_y3] == 0)
		{
			ghost_x3 = nghost_x3;
			ghost_y3 = nghost_y3;
		}
		if (nghost_x4 < 0) nghost_x4 = 0;
		if (nghost_y4 < 0) nghost_y4 = 0;


		if (a[nghost_x4][nghost_y4] == 0)
		{
			ghost_x4 = nghost_x4;
			ghost_y4 = nghost_y4;
		}

		//BGround.set_sprite_position(0, pacman_x, pacman_y); //first argument 0 .. pacman picture

		/*if (input_info.left_cursor_down == 1)
			ghost_x--;
			if (input_info.right_cursor_down == 1)
			ghost_x++;
			if (input_info.up_cursor_down == 1)
			ghost_y--;
			if (input_info.down_cursor_down == 1)
			ghost_y++;*/

		BGround.set_sprite_position(1, ghost_x, ghost_y);//first argument 1 .. ghost picture
		BGround.set_sprite_position(2, ghost_x2, ghost_y2);
		BGround.set_sprite_position(3, ghost_x3, ghost_y3);
		BGround.set_sprite_position(4, ghost_x4, ghost_y4);

		///////////////////////////////////////////////////////////////////////////////




		// awsd keys
		static int dir = 0;
		static int pos_x = 250;
		static int pos_y = 280;
		int npos_x = pos_x, npos_y = pos_y;

		int rx, ry;//relative positions
		rx = pos_x - 10;
		ry = pos_y - 10;
		if (input_info.a_key_down == 1)
		{
			if ((field[rx / 30 - 1][ry / 30] <= 0 && dir == 0) || dir == 1)
			{
				dir = 2;

			}

		}
		if (input_info.d_key_down == 1)
		{
			if ((field[rx / 30 + 1][ry / 30] <= 0 && dir == 0) || dir == 2)
			{
				dir = 1;

			}

		}
		if (input_info.w_key_down == 1)
		{
			if ((field[rx / 30][ry / 30 - 1] <= 0 && dir == 0) || dir == 4)
			{
				dir = 3;

			}

		}
		if (input_info.s_key_down == 1)
		{
			if ((field[rx / 30][ry / 30 + 1] <= 0 && dir == 0) || dir == 3)
			{
				dir = 4;

			}

		}





		pacman(pos_x, pos_y, dir); // pacman goes to the position


		//if (a[npos_x][npos_y]=)

		if (dir == 1)
		{
			pos_x++;
		}

		if (dir == 2)
		{
			pos_x--;
		}
		if (dir == 3)
		{
			pos_y--;
		}

		if (dir == 4)
		{
			pos_y++;
		}
		rx = pos_x - 10;
		ry = pos_y - 10;
		if (rx % 30 == 0 && (dir == 1 || dir == 2))
			dir = 0;
		if (ry % 30 == 0 && (dir == 3 || dir == 4))
			dir = 0;


		static int highscore = 0;
		char b[100];
		if (field[rx / 30][ry / 30] == -1)
		{
			field[rx / 30][ry / 30] = 0;
			highscore = highscore + 15;
		}


		// Draws highscore
		sprintf_s(b, "Score = %d", highscore);
		draw_text(b, 10, 10, 255, 255, 255);





		//Random ghost #1
		static int gdir = 1;
		static int g2dir = 2, g3dir = 4, g4dir = 1;

		if (gdir == 1)
		{
			ghost_x++;
		}
		if (gdir == 2)
		{
			ghost_x--;
		}
		if (gdir == 3)
		{
			ghost_y++;
		}
		if (gdir == 4)
		{
			ghost_y--;
		}
		if (gdir == 0)
		{
			gdir = rand() % 4 + 1;
		}
		if (g2dir == 1)
		{
			ghost_x2++;
		}
		if (g2dir == 2)
		{
			ghost_x2--;
		}
		if (g2dir == 3)
		{
			ghost_y2++;
		}
		if (g2dir == 4)
		{
			ghost_y2--;
		}
		if (g2dir == 0)
		{
			g2dir = rand() % 4 + 1;
		}
		if (g3dir == 1)
		{
			ghost_x3++;
		}
		if (g3dir == 2)
		{
			ghost_x3--;
		}
		if (g3dir == 3)
		{
			ghost_y3++;
		}
		if (g3dir == 4)
		{
			ghost_y3--;
		}
		if (g3dir == 0)
		{
			g3dir = rand() % 4 + 1;
		}
		if (g4dir == 1)
		{
			ghost_x4++;
		}
		if (g4dir == 2)
		{
			ghost_x4--;
		}
		if (g4dir == 3)
		{
			ghost_y4++;
		}
		if (g4dir == 4)
		{
			ghost_y4--;
		}
		if (g4dir == 0)
		{
			g4dir = rand() % 4 + 1;
		}

		if (abs(pos_y - ghost_y2) < 10)
		{
			if (ghost_x2>pos_x)
				g2dir = 2;
			if (ghost_x2 < pos_x)
				g2dir = 1;
		}
		if (abs(pos_y - ghost_y) < 10)
		{
			if (ghost_x>pos_x)
				gdir = 2;
			if (ghost_x < pos_x)
				gdir = 1;
		}
		if (abs(pos_y - ghost_y3) < 10)
		{
			if (ghost_x3>pos_x)
				g3dir = 2;
			if (ghost_x3 < pos_x)
				g3dir = 1;

		}
		if (abs(pos_y - ghost_y4) < 10)
		{
			if (ghost_x4>pos_x)
				g4dir = 2;
			if (ghost_x4 < pos_x)
				g4dir = 1;
		}
		if (abs(pos_x - ghost_x) < 10)
		{
			if (ghost_y>pos_y)
				gdir = 4;
			if (ghost_y < pos_y)
				gdir = 3;
		}
		if (abs(pos_x - ghost_x2) < 10)
		{
			if (ghost_y2>pos_y)
				g2dir = 4;
			if (ghost_y2 < pos_y)
				g2dir = 3;
		}
		if (abs(pos_x - ghost_x3) < 10)
		{
			if (ghost_y3>pos_y)
				g3dir = 4;
			if (ghost_y3 < pos_y)
				g3dir = 3;
		}
		if (abs(pos_x - ghost_x4) < 10)
		{
			if (ghost_y4>pos_y)
				g4dir = 4;
			if (ghost_y4 < pos_y)
				g4dir = 3;
		}
		if (gdir == 1)
		{
			if (field[(ghost_x - 10) / 30 + 1][ghost_y / 30] == 1)
			{
				gdir = 0;
			}
		}
		if (gdir == 2)
		{
			if (field[(ghost_x + 20) / 30 - 1][ghost_y / 30] == 1)
			{
				gdir = 0;
			}
		}
		if (gdir == 3)
		{
			if (field[ghost_x / 30][(ghost_y - 10) / 30 + 1] == 1) // ghost_y + number
			{
				gdir = 0;
			}
		}
		if (gdir == 4)
		{
			if (field[ghost_x / 30][(ghost_y + 20) / 30 - 1] == 1)
			{
				gdir = 0;
			}
		}
		if (g2dir == 1)
		{
			if (field[(ghost_x2 - 15) / 30 + 1][ghost_y2 / 30] == 1)
			{
				g2dir = 0;
			}
		}
		if (g2dir == 2)
		{
			if (field[(ghost_x2 + 20) / 30 - 1][ghost_y2 / 30] == 1)
			{
				g2dir = 0;
			}
		}
		if (g2dir == 3)
		{
			if (field[ghost_x2 / 30][(ghost_y2 - 15) / 30 + 1] == 1) // ghost_y + number
			{
				g2dir = 0;
			}
		}
		if (g2dir == 4)
		{
			if (field[ghost_x2 / 30][(ghost_y2 + 20) / 30 - 1] == 1)
			{
				g2dir = 0;
			}
		}
		if (g3dir == 1)
		{
			if (field[(ghost_x3 - 10) / 30 + 1][ghost_y3 / 30] == 1)
			{
				g3dir = 0;
			}
		}
		if (g3dir == 2)
		{
			if (field[(ghost_x3 + 20) / 30 - 1][ghost_y3 / 30] == 1)
			{
				g3dir = 0;
			}
		}
		if (g3dir == 3)
		{
			if (field[ghost_x3 / 30][(ghost_y3 - 10) / 30 + 1] == 1) // ghost_y + number
			{
				g3dir = 0;
			}
		}
		if (g3dir == 4)
		{
			if (field[ghost_x3 / 30][(ghost_y3 + 20) / 30 - 1] == 1)
			{
				g3dir = 0;
			}
		}
		if (g4dir == 1)
		{
			if (field[(ghost_x4 - 10) / 30 + 1][ghost_y4 / 30] == 1)
			{
				g4dir = 0;
			}
		}
		if (g4dir == 2)
		{
			if (field[(ghost_x4 + 20) / 30 - 1][ghost_y4 / 30] == 1)
			{
				g4dir = 0;
			}
		}
		if (g4dir == 3)
		{
			if (field[ghost_x4 / 30][(ghost_y4 - 10) / 30 + 1] == 1) // ghost_y + number
			{
				g4dir = 0;
			}
		}
		if (g4dir == 4)
		{
			if (field[ghost_x4 / 30][(ghost_y4 + 20) / 30 - 1] == 1)
			{
				g4dir = 0;
			}
		}

		/*if (highscore == 285)
		{
			BGround.set_sprite_position(0, 100, 250);
		}*/
		//Pacman & Ghost collision
		static int Mp_x, Mp_y;
		static int length, length2, length3, length4, X, Y, X2, Y2, X3, Y3, X4, Y4;
		Mp_x = pos_x + 8;
		Mp_y = pos_y + 8;
		X = pos_x - ghost_x;
		Y = pos_y - ghost_y;
		X2 = pos_x - ghost_x2;
		Y2 = pos_y - ghost_y2;
		X3 = pos_x - ghost_x3;
		Y3 = pos_y - ghost_y3;
		X4 = pos_x - ghost_x4;
		Y4 = pos_y - ghost_y4;
		length = sqrt((X*X) + (Y*Y));
		length2 = sqrt((X2*X2) + (Y2*Y2));
		length3 = sqrt((X3*X3) + (Y3*Y3));
		length4 = sqrt((X4*X4) + (Y4*Y4));




		char t[100];
		static int lives = 3;
		sprintf(t, "%d", lives);
		draw_text(t, 450, 10, 255, 255, 255);

		int startpos_x = 250, startpos_y = 280;
		if (length < 10)
		{
			lives--;
			pos_x = startpos_x;
			pos_y = startpos_y;
			ghost_x = 40;
			ghost_y = 40;
			ghost_x2 = 300;
			ghost_y2 = 40;
			ghost_x3 = 300;
			ghost_y3 = 300;

		}
		if (length2 < 10)
		{
			lives--;
			pos_x = startpos_x;
			pos_y = startpos_y;
			ghost_x = 40;
			ghost_y = 40;
			ghost_x2 = 300;
			ghost_y2 = 40;
			ghost_x3 = 300;
			ghost_y3 = 300;

		}
		if (length3 < 10)
		{
			lives--;
			pos_x = startpos_x;
			pos_y = startpos_y;
			ghost_x = 40;
			ghost_y = 40;
			ghost_x2 = 300;
			ghost_y2 = 40;
			ghost_x3 = 300;
			ghost_y3 = 300;

		}
		if (length4 < 10)
		{
			lives--;
			pos_x = startpos_x;
			pos_y = startpos_y;
			ghost_x = 40;
			ghost_y = 40;
			ghost_x2 = 300;
			ghost_y2 = 40;
			ghost_x3 = 300;
			ghost_y3 = 300;

		}

		/*static int fx = 500, fy = 500; // fruit
		int nfx = fx, nfy = fy;
		if (nfx < 0)
			fx = 0;
		if (nfy < 0)
			fy = 0;
		if (a[nfx][nfy] == 0)
			{
			fx = nfx;
			fy = nfy;
			}
		BGround.set_sprite_position(0, fx, fy);
		static int initf = 1;
		int h;
		if (initf = 1)
		{
			h = rand() % 60 + 1;
			if (h == 10)
			{
				fx = 100;
				fy = 250;
				initf = 0;
			}
		}
		static int Xf, Yf, lengthf;
		if (h == 10)
		{
			Xf = pos_x - fx;
			Yf = pos_y - fy;
			lengthf = ((Xf*Xf) + (Yf*Yf));
			if (lengthf < 10)
				{
				BGround.set_sprite_position(0, fx, fy);
				highscore = highscore + 400;
				fx = 500;
				fy = 500;
				}
		
			
		}*/

		
		char game[] = "GAME OVER";
	//	char starto[] = "Start Over?";
		if (lives == 0 || highscore ==2085)
		{
			sprintf_s(b, "Score = %d", highscore);
			draw_text(b, 213, 260, 255, 255, 255);
			lives = 0;
			draw_text(game, 210, 233, 255, 255, 255);
			pos_x = 250;
			pos_y = 220;
			//draw_text(starto, 215, 300, 255, 255, 255); //Cant get the restart to work right all the time, it's iffy.
		/*	if (input_info.l_button_down && (input_info.x_mouse >= 215 && input_info.x_mouse <= 300))
			{
				if (input_info.l_button_down && (input_info.y_mouse >= 300 && input_info.y_mouse <= 350))
				{
					lives = 3;
					highscore = 0;
					init = 1;
					pos_x = startpos_x;
					pos_y = startpos_y;
					ghost_x = 40;
					ghost_y = 40;
					ghost_x2 = 300;
					ghost_y2 = 40;
					ghost_x3 = 300;
					ghost_y3= 300;
					status = title;
				}

			}*/
		}
	}
}
		

	



