#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 800), "PingPong");

	RectangleShape line(Vector2f(5, 800));
	line.setFillColor(Color::White);
	line.setPosition(400, 0);

	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12,
		t13, t14, t15, t16, t17, t18, t19, t20;
	t1.loadFromFile("F:/ych/pingpong/print/player.png");
	t2.loadFromFile("F:/ych/pingpong/print/ball.png");
	t3.loadFromFile("F:/ych/pingpong/print/nazv.png");
	t4.loadFromFile("F:/ych/pingpong/print/butplay.png");
	t5.loadFromFile("F:/ych/pingpong/print/nastroy.png");
	t6.loadFromFile("F:/ych/pingpong/print/exit.png");
	t7.loadFromFile("F:/ych/pingpong/print/KO.png");
	t8.loadFromFile("F:/ych/pingpong/print/cifr.png");
	t9.loadFromFile("F:/ych/pingpong/print/bsc.png");
	t10.loadFromFile("F:/ych/pingpong/print/gal.png");
	t11.loadFromFile("F:/ych/pingpong/print/npok.png");
	t12.loadFromFile("F:/ych/pingpong/print/back.png");
	t13.loadFromFile("F:/ych/pingpong/print/UI.png");
	t14.loadFromFile("F:/ych/pingpong/print/nazpause.png");
	t15.loadFromFile("F:/ych/pingpong/print/uprav.png");
	t16.loadFromFile("F:/ych/pingpong/print/nac.png");
	t17.loadFromFile("F:/ych/pingpong/print/win.png");
	t18.loadFromFile("F:/ych/pingpong/print/winbut.png");
	t19.loadFromFile("F:/ych/pingpong/print/pau.png");
	t20.loadFromFile("F:/ych/pingpong/print/continue.png");

	bool menu = true, setting = false, pok = true, game = false,
		animation = true, play = false, stop = false, pause = false;

	Sprite player[2], ball(t2);
	for (int i = 0; i < 2; i++) {
		player[i].setTexture(t1);
		player[i].setTextureRect(IntRect(40 * i, 0, 36, 208));
		player[i].setPosition(765 * i, 250);
	}
	ball.setScale(2, 2);
	ball.setPosition(40, 320);
	int kx = 1, ky = 1;

	Sprite naz(t3), butplay(t4), nastroy(t5), exit(t6);
	naz.setPosition(10, 50);
	butplay.setPosition(500, 200);
	nastroy.setPosition(470, 300);
	exit.setPosition(500, 450);

	Sprite KO(t7), cifr(t8), bsc(t9), gal(t10), npok(t11), back(t12);
	KO.setPosition(440, 150);
	cifr.setTextureRect(IntRect(150, 0, 50, 75));
	cifr.setPosition(590, 200);
	bsc.setPosition(540, 300);
	gal.setTextureRect(IntRect(0, 0, 71, 71));
	gal.setPosition(360, 630);
	npok.setPosition(440, 620);
	back.setPosition(50, 650);
	int c = 3;

	Sprite UI(t13), nazpause(t14), uprav[2], nac(t16);
	UI.setPosition(150, 100);
	nazpause.setPosition(180, 340);
	nac.setPosition(450, 650);
	for (int i = 0; i < 2; i++) {
		uprav[i].setTexture(t15);
		uprav[i].setTextureRect(IntRect(118 * i, 0, 118, 217));
		uprav[i].setPosition(50 + 550 * i, 250);
	}

	Sprite score[2];
	int sc[2] = { 0, 0 };
	for (int i = 0; i < 2; i++) {
		score[i].setTexture(t8);
		score[i].setPosition(700 * i, 10);
	}

	Sprite win(t17), winbut[2];
	win.setPosition(150, 150);
	for (int i = 0; i < 2; i++) {
		winbut[i].setTexture(t18);
		winbut[i].setPosition(50 + 425 * i, 600);
	}
	winbut[0].setTextureRect(IntRect(0, 0, 302, 78));
	winbut[1].setTextureRect(IntRect(302, 0, 281, 78));

	Sprite pau(t19), con(t20), pbut[2];
	pau.setPosition(50, 120);
	con.setPosition(450, 150);
	for (int i = 0; i < 2; i++)
		pbut[i].setTexture(t18);
	pbut[0].setPosition(450, 350);
	pbut[1].setPosition(475, 550);
	pbut[0].setTextureRect(IntRect(0, 0, 302, 78));
	pbut[1].setTextureRect(IntRect(302, 0, 281, 78));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left) {
					Vector2i pos = Mouse::getPosition(window);

					if (menu) {
						if (exit.getGlobalBounds().contains(pos.x, pos.y))
							window.close();

						if (nastroy.getGlobalBounds().contains(pos.x, pos.y)) {
							menu = false;
							setting = true;
						}

						if (butplay.getGlobalBounds().contains(pos.x, pos.y)) {
							game = true;
							menu = false;

							if (!pok) {
								animation = false;
								play = true;

								for (int i = 0; i < 2; i++)
									player[i].setPosition(765 * i, 250);
								ball.setPosition(40, 320);
								kx = 1, ky = 1;
							}
						}
					}

					else if (setting) {
						if (bsc.getGlobalBounds().contains(pos.x, pos.y) && pos.x <= 620 &&
							c < 11)
							c++;

						else if (pos.x >= 620 && bsc.getGlobalBounds().contains(pos.x, pos.y) && c > 3)
							c--;

						if (gal.getGlobalBounds().contains(pos.x, pos.y)) {
							if (pok) {
								pok = false;

								gal.setTextureRect(IntRect(71, 0, 71, 71));
							}

							else if (!pok) {
								pok = true;

								gal.setTextureRect(IntRect(0, 0, 71, 71));
							}
						}

						if (back.getGlobalBounds().contains(pos.x, pos.y)) {
							menu = true;
							setting = false;
						}
					}

					else if (game && pok) {
						if (back.getGlobalBounds().contains(pos.x, pos.y)) {
							menu = true;
							game = false;
						}

						if (nac.getGlobalBounds().contains(pos.x, pos.y)) {
							game = false;
							animation = false;
							play = true;

							for (int i = 0; i < 2; i++)
								player[i].setPosition(765 * i, 250);
							ball.setPosition(40, 320);
							kx = 1, ky = 1;
						}
					}

					else if (stop) {
						if (winbut[0].getGlobalBounds().contains(pos.x, pos.y)) {
							for (int i = 0; i < 2; i++)
								sc[i] = 0;

							stop = false;
						}

						if (winbut[1].getGlobalBounds().contains(pos.x, pos.y)) {
							menu = true;
							animation = true;
							stop = false;
							play = false;

							for (int i = 0; i < 2; i++)
								sc[i] = 0;
						}
					}

					else if (pause) {
						if (con.getGlobalBounds().contains(pos.x, pos.y))
							pause = false;

						if (pbut[0].getGlobalBounds().contains(pos.x, pos.y)) {
							for (int i = 0; i < 2; i++)
								sc[i] = 0;

							pause = false;

							for (int i = 0; i < 2; i++)
								player[i].setPosition(765 * i, 250);
							ball.setPosition(40, 320);
							kx = 1, ky = 1;
						}

						if (pbut[1].getGlobalBounds().contains(pos.x, pos.y)) {
							pause = false;
							play = false;
							animation = true;
							menu = true;

							for (int i = 0; i < 2; i++)
								sc[i] = 0;
							for (int i = 0; i < 2; i++)
								player[i].setPosition(765 * i, 250);
							ball.setPosition(40, 320);
							kx = 1, ky = 1;
						}
					}
				}
		}

		if (!stop && !pause)
			ball.move(0.5 * kx, 0.5 * ky);

		Vector2f b = ball.getPosition();
		if (b.y < 0 || b.y > 730)
			ky *= -1;

		Vector2f p[2];
		for (int i = 0; i < 2; i++) {
			p[i] = player[i].getPosition();

			if (ball.getGlobalBounds().intersects(player[i].getGlobalBounds())) {
				kx *= -1;

				if (kx < 0)
					ball.move(-10, 0);
			}

			if (p[i].y > 600)
				player[i].setPosition(765 * i, 600);
			if (p[i].y < 0)
				player[i].setPosition(765 * i, 0);
		}

		if (animation)
			for (int i = 0; i < 2; i++) {
				if (b.y > p[i].y)
					player[i].move(0, 0.5);
				if (b.y < p[i].y)
					player[i].move(0, -0.5);
			}

		else if (play) {
			if (!stop && !pause) {
				if (Keyboard::isKeyPressed(Keyboard::Up))
					player[1].move(0, -0.75);
				if (Keyboard::isKeyPressed(Keyboard::Down))
					player[1].move(0, 0.75);
				if (Keyboard::isKeyPressed(Keyboard::W))
					player[0].move(0, -0.75);
				if (Keyboard::isKeyPressed(Keyboard::S))
					player[0].move(0, 0.75);
			}

			if (b.x < -100) {
				ball.setPosition(700, 320);

				sc[1]++;
			}
			else if (b.x > 800) {
				ball.setPosition(40, 320);

				sc[0]++;
			}

			for (int i = 0; i < 2; i++)
				if (sc[i] == c) {
					stop = true;

					for (int i = 0; i < 2; i++)
						player[i].setPosition(765 * i, 250);
					ball.setPosition(40, 320);
					kx = 1, ky = 1;
				}

			if (sc[0] == c)
				win.setTextureRect(IntRect(0, 0, 493, 57));
			else if (sc[1] == c)
				win.setTextureRect(IntRect(0, 57, 493, 57));

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				pause = true;
		}

		for (int i = 0; i < 2; i++) {
			if (sc[i] < 10)
				score[i].setTextureRect(IntRect(50 * sc[i], 0, 50, 75));
			else if (sc[i] == 10)
				score[i].setTextureRect(IntRect(500, 0, 75, 75));
			else if (sc[i] == 11)
				score[i].setTextureRect(IntRect(580, 0, 75, 75));
		}

		if (c < 10)
			cifr.setTextureRect(IntRect(50 * c, 0, 50, 75));
		else if (c == 10)
			cifr.setTextureRect(IntRect(500, 0, 75, 75));
		else if (c == 11)
			cifr.setTextureRect(IntRect(580, 0, 75, 75));

		window.clear();
		window.draw(line);

		for (int i = 0; i < 2; i++)
			window.draw(player[i]);
		window.draw(ball);

		if (menu) {
			window.draw(naz);
			window.draw(butplay);
			window.draw(nastroy);
			window.draw(exit);
		}

		if (setting) {
			window.draw(KO);
			window.draw(cifr);
			window.draw(bsc);
			window.draw(gal);
			window.draw(npok);
			window.draw(back);
		}

		if (game && pok) {
			window.draw(UI);
			window.draw(nazpause);
			window.draw(back);
			window.draw(nac);
			for (int i = 0; i < 2; i++)
				window.draw(uprav[i]);
		}

		if (play)
			for (int i = 0; i < 2; i++)
				window.draw(score[i]);

		if (stop) {
			window.draw(win);
			for (int i = 0; i < 2; i++)
				window.draw(winbut[i]);
		}

		if (pause) {
			window.draw(pau);
			window.draw(con);
			for (int i = 0; i < 2; i++)
				window.draw(pbut[i]);
		}

		window.display();
	}

	return 0;
}