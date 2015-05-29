//Gerardo Peregrina
//Duckhunt
//Hw3
//Worked on the duck image, 
//bullet score image, and duck score image

#include <GL/glx.h>
#include "ppm.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>


//Function from Rainforest file
unsigned char *buildAlphaData(Ppmimage *img) {
        // add 4th component to RGB stream...
        int a,b,c;
        unsigned char *newdata, *ptr;
        unsigned char *data = (unsigned char *)img->data;
        //newdata = (unsigned char *)malloc(img->width * img->height * 4);
        newdata = new unsigned char[img->width * img->height * 4];
        ptr = newdata;
        for (int i=0; i<img->width * img->height * 3; i+=3) {
                a = *(data+0);
                b = *(data+1);
                c = *(data+2);
                *(ptr+0) = a;
                *(ptr+1) = b;
                *(ptr+2) = c;
                *(ptr+3) = (a|b|c);
                ptr += 4;
                data += 3;
        }
        return newdata;
}

void generateTexture(Ppmimage *bulletImage, GLuint *bulletTexture, Ppmimage *duckscoreImage, GLuint *duckscoreTexture
			, Ppmimage *duckscoreImage2, GLuint *duckscoreTexture2, Ppmimage *duckImage, GLuint *duckTexture
			, GLuint *duckSil, Ppmimage *duckImage2, GLuint *duckTexture2, GLuint *duckSil2
			, Ppmimage *duckImage3, GLuint *duckTexture3, GLuint *duckSil3
			, Ppmimage *duckImage4, GLuint *duckTexture4, GLuint *duckSil4
			, Ppmimage *duckImage5, GLuint *duckTexture5, GLuint *duckSil5
			, Ppmimage *backgroundImage, GLuint *backgroundTexture
			, Ppmimage *backgroundTransImage, GLuint *backgroundTransTexture
            , Ppmimage *gameoverbgImage, GLuint *gameoverbgTexture) {
	
		//-------------------------------------------------------------------
        //bullet
        glGenTextures(1, bulletTexture);
        bulletImage = ppm6GetImage("./images/bullet.ppm");
        int w1 = bulletImage->width;
        int h1 = bulletImage->height;
        glBindTexture(GL_TEXTURE_2D, *bulletTexture);
        //
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w1, h1, 0, GL_RGB, GL_UNSIGNED_BYTE, bulletImage->data);
        //-------------------------------------------------------------------

        //-------------------------------------------------------------------
        //White duck score sprite       
        glGenTextures(1, duckscoreTexture);
        duckscoreImage = ppm6GetImage("./images/duck_score_1.ppm");
        int w2 = duckscoreImage->width;
        int h2 = duckscoreImage->height;
        glBindTexture(GL_TEXTURE_2D, *duckscoreTexture);
        //
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w2, h2, 0, GL_RGB, GL_UNSIGNED_BYTE, duckscoreImage->data);
        //-------------------------------------------------------------------

        //-------------------------------------------------------------------
        //Red duck score sprite 
        glGenTextures(1, duckscoreTexture2);
        duckscoreImage2 = ppm6GetImage("./images/duck_score_2.ppm");
        int w3 = duckscoreImage2->width;
        int h3 = duckscoreImage2->height;
        glBindTexture(GL_TEXTURE_2D, *duckscoreTexture2);
        //
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w3, h3, 0, GL_RGB, GL_UNSIGNED_BYTE, duckscoreImage2->data);
        //-------------------------------------------------------------------

        //-------------------------------------------------------------------
        //duck sprite
        glGenTextures(1, duckTexture);
        glGenTextures(1, duckSil);
        duckImage = ppm6GetImage("./images/ducks1.ppm");
        int w4 = duckImage->width;
        int h4 = duckImage->height;
        glBindTexture(GL_TEXTURE_2D, *duckTexture);
        //
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w4, h4, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage->data);
        //-------------------------------------------------------------------
	
        //-------------------------------------------------------------------
        //duck silhouette 
        glBindTexture(GL_TEXTURE_2D, *duckSil);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        ////must build a new set of data...
        unsigned char *silhouetteData = buildAlphaData(duckImage);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w4, h4, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData);
        delete [] silhouetteData;
        //-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck sprite 2
		glGenTextures(1, duckTexture2);
		glGenTextures(1, duckSil2);
		duckImage2 = ppm6GetImage("./images/ducks2.ppm");
		int w5 = duckImage2->width;
		int h5 = duckImage2->height;
		glBindTexture(GL_TEXTURE_2D, *duckTexture2);
		//
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, w5, h5, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage2->data);
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck silhouette 2 
		glBindTexture(GL_TEXTURE_2D, *duckSil2);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		////must build a new set of data...
		unsigned char *silhouetteData2 = buildAlphaData(duckImage2);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w5, h5, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData2);
		delete [] silhouetteData2;
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck sprite 3
		glGenTextures(1, duckTexture3);
		glGenTextures(1, duckSil3);
		duckImage3 = ppm6GetImage("./images/shotduck1.ppm");
		int w6 = duckImage3->width;
		int h6 = duckImage3->height;
		glBindTexture(GL_TEXTURE_2D, *duckTexture3);
		//
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, w6, h6, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage3->data);
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck silhouette 3 
		glBindTexture(GL_TEXTURE_2D, *duckSil3);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		////must build a new set of data...
		unsigned char *silhouetteData3 = buildAlphaData(duckImage3);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w6, h6, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData3);
		delete [] silhouetteData3;
		//-------------------------------------------------------------------
		
		//-------------------------------------------------------------------
		//duck sprite 4
		glGenTextures(1, duckTexture4);
		glGenTextures(1, duckSil4);
		duckImage4 = ppm6GetImage("./images/shotduck2.ppm");
		int w7 = duckImage4->width;
		int h7 = duckImage4->height;
		glBindTexture(GL_TEXTURE_2D, *duckTexture4);
		//
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, w7, h7, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage4->data);
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck silhouette 4 
		glBindTexture(GL_TEXTURE_2D, *duckSil4);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		////must build a new set of data...
		unsigned char *silhouetteData4 = buildAlphaData(duckImage4);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w7, h7, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData4);
		delete [] silhouetteData4;
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck sprite 5
		glGenTextures(1, duckTexture5);
		glGenTextures(1, duckSil5);
		duckImage5 = ppm6GetImage("./images/ducks3.ppm");
		int w8 = duckImage5->width;
		int h8 = duckImage5->height;
		glBindTexture(GL_TEXTURE_2D, *duckTexture5);
		//
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, w8, h8, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage5->data);
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//duck silhouette 5
		glBindTexture(GL_TEXTURE_2D, *duckSil5);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		////must build a new set of data...
		unsigned char *silhouetteData5 = buildAlphaData(duckImage5);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w8, h8, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData5);
		delete [] silhouetteData5;
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//background textures
		//create opengl texture elements
		glGenTextures(1, backgroundTexture);
		glBindTexture(GL_TEXTURE_2D, *backgroundTexture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, backgroundImage->width, backgroundImage->height, 0, GL_RGB, GL_UNSIGNED_BYTE, backgroundImage->data);


		//-------------------------------------------------------------------
		//forest transparent part
		glBindTexture(GL_TEXTURE_2D, *backgroundTransTexture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		//must build a new set of data...
		int w9 = backgroundTransImage->width;
		int h9 = backgroundTransImage->height;
		unsigned char *ftData = buildAlphaData(backgroundTransImage);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w9, h9, 0, GL_RGBA, GL_UNSIGNED_BYTE, ftData);
		delete [] ftData;
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		//gameover
		glGenTextures(1, gameoverbgTexture);
		glBindTexture(GL_TEXTURE_2D, *gameoverbgTexture);
		//
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, gameoverbgImage->width, gameoverbgImage->height, 0, GL_RGB, GL_UNSIGNED_BYTE, gameoverbgImage->data);
		//-------------------------------------------------------------------


}

/*
void DisplayBullets(Game *game, Sprite bullet_sprite) {
    //-------------------------------------------------------------------
    //Displaying bullets
    glColor3ub(90, 140, 90);
    s = &game->box[0];
    glPushMatrix();
    glTranslatef(s->center.x, s->center.y, s->center.z);
    w = s->width;
    h = s->height;
    int num = 0, dist = 0;
    if (game->bullets == 3) {
	    num = 3, dist = 80;
    }
    if (game->bullets == 2) {
	    num = 2, dist = 60;
    }
    if (game->bullets == 1) {
	    num = 1, dist = 40;
    }
    if (game->bullets == 0) {
	    num = 0, dist = 0;
    }
    if (game->bullets != 0) {
	    for (int i=0;i<num;i++) {
		    bullet_sprite.pos[0] = dist - (i * 20);
		    bullet_sprite.pos[1] = 40;
		    bullet_sprite.pos[2] = 0;
		    float wid = 10.0f;
		    glPushMatrix();
		    glTranslatef(bullet_sprite.pos[0], bullet_sprite.pos[1], bullet_sprite.pos[2]);
		    glBindTexture(GL_TEXTURE_2D, bulletTexture);
		    glEnable(GL_ALPHA_TEST);
		    glAlphaFunc(GL_GREATER, 0.0f);
		    glColor4ub(255,255,255,255);
		    glBegin(GL_QUADS);
		    if (bullet_sprite.vel[0] > 0.0) {
			    glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
			    glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
			    glTexCoord2f(1.0f, 0.0f); glVertex2i( wid, wid);
			    glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
		    } else {
			    glTexCoord2f(1.0f, 1.0f); glVertex2i(-wid,-wid);
			    glTexCoord2f(1.0f, 0.0f); glVertex2i(-wid, wid);
			    glTexCoord2f(0.0f, 0.0f); glVertex2i( wid, wid);
			    glTexCoord2f(0.0f, 1.0f); glVertex2i( wid,-wid);
		    }
		    glEnd();
		    glPopMatrix();
		    glDisable(GL_ALPHA_TEST);
	    }
    }
    r.bot = s->height;
    r.left = s->width;
    glVertex2i(-w, -h);
    glVertex2i(-w, h);
    glVertex2i(w, h);
    glVertex2i(w, -h);
    glEnd();
    glPopMatrix();
}

*/




//Second Duck Picture, not working
/*
        //-------------------------------------------------------------------
        //duck sprite 2
        glGenTextures(1, &duckTexture2);
        glGenTextures(1, &duckSil2);
        duckImage2 = ppm6GetImage("./images/ducks2.ppm");
        int w5 = duckImage2->width;
        int h5 = duckImage2->height;
        glBindTexture(GL_TEXTURE_2D, duckTexture2);
        //
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w5, h5, 0, GL_RGB, GL_UNSIGNED_BYTE, duckImage2->data);
        //-------------------------------------------------------------------

        //-------------------------------------------------------------------
        //duck silhouette 2 
        glBindTexture(GL_TEXTURE_2D, duckSil2);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        ////must build a new set of data...
        unsigned char *silhouetteData2 = buildAlphaData(duckImage2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w5, h5, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, silhouetteData2);
        delete [] silhouetteData2;
        //-------------------------------------------------------------------

*/

/*
//duck sprite
typedef double Arr[3];
struct Sprite {
    Arr pos;
    Arr vel;
};
//First Duck Sprite
Sprite duck_sprite;
Ppmimage *duckImage=NULL;
GLuint duckTexture;
GLuint duckSil;
//Second Duck Sprite
Sprite duck_sprite2;
Ppmimage *duckImage2=NULL;
GLuint duckTexture2;
GLuint duckSil2;
int show_duck = 0;
int silhouette = 1;
//Bullet Sprite
Sprite bullet_sprite;
Ppmimage *bulletImage=NULL;
GLuint bulletTexture;
//White duck Sprite
Sprite duckscore_sprite;
Ppmimage *duckscoreImage=NULL;
GLuint duckscoreTexture;
//Red duck sprite
Sprite duckscore_sprite2;
Ppmimage *duckscoreImage2=NULL;
GLuint duckscoreTexture2;



//-------------------------------------------------------------------
//Displaying duck score sprites
glColor3ub(90, 140, 90);
s = &game->box[1];
glPushMatrix();
glTranslatef(s->center.x, s->center.y, s->center.z);
w = s->width;
h = s->height;
//Duck score sprites
if (game->duckShot <= 10) {
	for (int i=0;i<=9;i++) {
		duckscore_sprite.pos[0] = 70 + (i * 25);
		duckscore_sprite.pos[1] = 42;
		duckscore_sprite.pos[2] = 0;
		float wid = 10.0f;
		glPushMatrix();
		glTranslatef(duckscore_sprite.pos[0], duckscore_sprite.pos[1], duckscore_sprite.pos[2]);
		glBindTexture(GL_TEXTURE_2D, duckscoreTexture);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0f);
		glColor4ub(255,255,255,255);
		glBegin(GL_QUADS);
		if (duckscore_sprite.vel[0] > 0.0) {
			glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
		} else {
			glTexCoord2f(1.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(0.0f, 1.0f); glVertex2i( wid,-wid);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_ALPHA_TEST);
	}
}
int loop = 0;
if (game->duckShot == 1) loop = 1;
if (game->duckShot == 2) loop = 2;
if (game->duckShot == 3) loop = 3;
if (game->duckShot == 4) loop = 4;
if (game->duckShot == 5) loop = 5;
if (game->duckShot == 6) loop = 6;
if (game->duckShot == 7) loop = 7;
if (game->duckShot == 8) loop = 8;
if (game->duckShot == 9) loop = 9;
if (game->duckShot == 10) loop = 10;
if (game->duckShot <= 9) {
	for (int i=0;i<loop;i++) {
		duckscore_sprite2.pos[0] = 70 + (i * 25);
		duckscore_sprite2.pos[1] = 42;
		duckscore_sprite2.pos[2] = 0;
		float wid = 10.0f;
		glPushMatrix();
		glTranslatef(duckscore_sprite2.pos[0], duckscore_sprite2.pos[1], duckscore_sprite2.pos[2]);
		glBindTexture(GL_TEXTURE_2D, duckscoreTexture2);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0f);
		glColor4ub(255,255,255,255);
		glBegin(GL_QUADS);
		if (duckscore_sprite2.vel[0] > 0.0) {
			glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
		} else {
			glTexCoord2f(1.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(0.0f, 1.0f); glVertex2i( wid,-wid);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_ALPHA_TEST);
	}
}


//------------------------------------------------------------------------------
//Duck image movement
if(show_duck) {
		glPushMatrix();
		//implement direction change 
		glTranslatef(duck_sprite.pos[0], duck_sprite.pos[1], duck_sprite.pos[2]);
		if (silhouette)
		{
			glBindTexture(GL_TEXTURE_2D, duckTexture);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.0f);
			glColor4ub(255,255,255,255);
		}
		glBegin(GL_QUADS);
		if (duck_sprite.vel[0] > 0.0) {
			glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
		} else {
			glTexCoord2f(1.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(0.0f, 1.0f); glVertex2i( wid,-wid);
		}
		//Duck2
		glTranslatef(duck_sprite2.pos[0], duck_sprite2.pos[1], duck_sprite2.pos[2]);
		if (silhouette)
		{
			glBindTexture(GL_TEXTURE_2D, duckTexture2);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.0f);
			glColor4ub(255,255,255,255);
		}
		glBegin(GL_QUADS);
		if (duck_sprite2.vel[0] > 0.0) {
			glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
		} else {
			glTexCoord2f(1.0f, 1.0f); glVertex2i(-wid,-wid);
			glTexCoord2f(1.0f, 0.0f); glVertex2i(-wid, wid);
			glTexCoord2f(0.0f, 0.0f); glVertex2i( wid, wid);
			glTexCoord2f(0.0f, 1.0f); glVertex2i( wid,-wid);
		}
		glEnd();
		glPopMatrix();
		}
		glDisable(GL_ALPHA_TEST);
}

*/












