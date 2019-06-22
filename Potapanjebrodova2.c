#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BRRED 10
#define BRSTUP 10
#define D_CARRIER 5
#define D_BATTLESHIP 4
#define D_CRUISER 3
#define D_SUBMARINE 3
#define D_DESTROYER 2

int main (void) {
	int matigrac[BRRED][BRSTUP] = {0}, matkomp[BRRED][BRSTUP] = {0};
	int i, j, pom, brojbodovaigrac = 0, brojbodovakomp = 0, red, stup, brojrundi = 0;
	char pom2;
	int igragotova = 0; /* pogodak = 0, streak = 0;
	int carrierdown = 0, battleshipdown = 0, cruiserdown = 0, submarinedown = 0, destroyerdown = 0; */
	
	srand(time(NULL));
	
	/* upute i komentari
	   postavi brodove 
	  od svakog po jedan	 duljina
			carrier				D_CARRIER
			battleship			4
			cruiser				3
			submarine			3
			destroyer			2		
	   ako je nula onda stavi vodoravno 
	   ako je jedan onda sravi okomito  */
	
	/* postavi plocu za igraca */
	if (1) {
	/* postavi carrier */
	if (rand()%2 == 0) {
	  /* odredi poziciju */
	  postavicarriervodoravnoplayer:
		red = rand()%BRRED;					/* random red izmedu [0, BRRED> */
		stup = rand()%(BRSTUP-D_CARRIER); 	/* random stupac izmedu [0, BRSTUP-duljinabroda> */
		pom = 0;
	  /* provjeri jesu li sva mjesta slobodna */
		for (j = stup; j < stup + D_CARRIER; j++) {
			pom += matigrac[red][j];
		}
	  /* postavi brod ako je sve u redu*/
		if (stup+D_CARRIER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_CARRIER; j++) {
				matigrac[red][j] = 1;
			}
		} 
	  /* ako nije ponovi postupak */
		  else {
			goto postavicarriervodoravnoplayer;
		}
	} else {
		postavicarrierokomitoplayer:
		red = rand()%(BRRED-D_CARRIER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_CARRIER; i++) {
			pom += matigrac[i][stup];
		}
		if (red+D_CARRIER < BRRED && pom == 0) {
			for (i = red; i < red + D_CARRIER; i++) {
				matigrac[i][stup] = 1;
			}
		} else {
			goto postavicarrierokomitoplayer;
		}
	}
	
	/* postavi battleship */
	if (rand()%2 == 0) {
	  postavibattleshipvodoravnoplayer:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_BATTLESHIP);
		pom = 0;
		for (j = stup; j < stup + D_BATTLESHIP; j++) {
			pom += matigrac[red][j];
		}
		if (stup+D_BATTLESHIP < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_BATTLESHIP; j++) {
				matigrac[red][j] = 2;
			}
		} else {
			goto postavibattleshipvodoravnoplayer;
		}
	}	else {
	  postavibattleshipokomitoplayer:
		red = rand()%(BRRED-D_BATTLESHIP);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_BATTLESHIP; i++) {
			pom += matigrac[i][stup];
		}
		if (red+D_BATTLESHIP < BRRED && pom == 0) {
			for (i = red; i < red + D_BATTLESHIP; i++) {
				matigrac[i][stup] = 2;
			}
		} else {
			goto postavibattleshipokomitoplayer;
		}
	}
	
	/*postavi cruiser */
	if (rand()%2 == 0) {
	  postavicruiservodoravnoplayer:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_CRUISER);
		pom = 0;
		for (j = stup; j < stup + D_CRUISER; j++) {
			pom += matigrac[red][j];
		}
		if (stup+D_CRUISER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_CRUISER; j++) {
				matigrac[red][j] = 3;
			}
		} else {
			goto postavicruiservodoravnoplayer;
		}
	}	else {
	  postavicruiserokomitoplayer:
		red = rand()%(BRRED-D_CRUISER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_CRUISER; i++) {
			pom += matigrac[i][stup];
		}
		if (red+D_CRUISER < BRRED && pom == 0) {
			for (i = red; i < red + D_CRUISER; i++) {
				matigrac[i][stup] = 3;
			}
		} else {
			goto postavicruiserokomitoplayer;
		}
	}
	
	/* postavi submarine */
	if (rand()%2 == 0) {
	  postavisubmarinevodoravnoplayer:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_SUBMARINE);
		pom = 0;
		for (j = stup; j < stup + D_SUBMARINE; j++) {
			pom += matigrac[red][j];
		}
		if (stup+D_SUBMARINE < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_SUBMARINE; j++) {
				matigrac[red][j] = 4;
			}
		} else {
			goto postavisubmarinevodoravnoplayer;
		}
	}	else {
	  postavisubmarineokomitoplayer:
		red = rand()%(BRRED-D_SUBMARINE);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_SUBMARINE; i++) {
			pom += matigrac[i][stup];
		}
		if (red+D_SUBMARINE < BRRED && pom == 0) {
			for (i = red; i < red + D_SUBMARINE; i++) {
				matigrac[i][stup] = 4;
			}
		} else {
			goto postavisubmarineokomitoplayer;
		}
	}
	
	/* postavi destroyer */
	if (rand()%2 == 0) {
	  postavidestroyervodoravnoplayer:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_DESTROYER);
		pom = 0;
		for (j = stup; j < stup + D_DESTROYER; j++) {
			pom += matigrac[red][j];
		}
		if (stup+D_DESTROYER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_DESTROYER; j++) {
				matigrac[red][j] = 5;
			}
		} else {
			goto postavidestroyervodoravnoplayer;
		}
	}	else {
	  postavidestroyerokomitoplayer:
		red = rand()%(BRRED-D_DESTROYER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_DESTROYER; i++) {
			pom += matigrac[i][stup];
		}
		if (red+D_DESTROYER < BRRED && pom == 0) {
			for (i = red; i < red + D_DESTROYER; i++) {
				matigrac[i][stup] = 5;
			}
		} else {
			goto postavidestroyerokomitoplayer;
		}
	}
	
	}
	
	/* postavi plocu za komp */
	if (2) {
	/* postavi carrier */
	if (rand()%2 == 0) {
	  /* odredi poziciju */
	  postavicarriervodoravnokomp:
		red = rand()%BRRED;					/* random red izmedu [0, BRRED> */
		stup = rand()%(BRSTUP-D_CARRIER); 	/* random stupac izmedu [0, BRSTUP-duljinabroda> */
		pom = 0;
	  /* provjeri jesu li sva mjesta slobodna */
		for (j = stup; j < stup + D_CARRIER; j++) {
			pom += matkomp[red][j];
		}
	  /* postavi brod ako je sve u redu*/
		if (stup+D_CARRIER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_CARRIER; j++) {
				matkomp[red][j] = 1;
			}
		} 
	  /* ako nije ponovi postupak */
		  else {
			goto postavicarriervodoravnokomp;
		}
	} else {
		postavicarrierokomitokomp:
		red = rand()%(BRRED-D_CARRIER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_CARRIER; i++) {
			pom += matkomp[i][stup];
		}
		if (red+D_CARRIER < BRRED && pom == 0) {
			for (i = red; i < red + D_CARRIER; i++) {
				matkomp[i][stup] = 1;
			}
		} else {
			goto postavicarrierokomitokomp;
		}
	}
	
	/* postavi battleship */
	if (rand()%2 == 0) {
	  postavibattleshipvodoravnokomp:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_BATTLESHIP);
		pom = 0;
		for (j = stup; j < stup + D_BATTLESHIP; j++) {
			pom += matkomp[red][j];
		}
		if (stup+D_BATTLESHIP < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_BATTLESHIP; j++) {
				matkomp[red][j] = 1;
			}
		} else {
			goto postavibattleshipvodoravnokomp;
		}
	}	else {
	  postavibattleshipokomitokomp:
		red = rand()%(BRRED-D_BATTLESHIP);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_BATTLESHIP; i++) {
			pom += matkomp[i][stup];
		}
		if (red+D_BATTLESHIP < BRRED && pom == 0) {
			for (i = red; i < red + D_BATTLESHIP; i++) {
				matkomp[i][stup] = 1;
			}
		} else {
			goto postavibattleshipokomitokomp;
		}
	}
	
	/*postavi cruiser */
	if (rand()%2 == 0) {
	  postavicruiservodoravnokomp:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_CRUISER);
		pom = 0;
		for (j = stup; j < stup + D_CRUISER; j++) {
			pom += matkomp[red][j];
		}
		if (stup+D_CRUISER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_CRUISER; j++) {
				matkomp[red][j] = 1;
			}
		} else {
			goto postavicruiservodoravnokomp;
		}
	}	else {
	  postavicruiserokomitokomp:
		red = rand()%(BRRED-D_CRUISER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_CRUISER; i++) {
			pom += matkomp[i][stup];
		}
		if (red+D_CRUISER < BRRED && pom == 0) {
			for (i = red; i < red + D_CRUISER; i++) {
				matkomp[i][stup] = 1;
			}
		} else {
			goto postavicruiserokomitokomp;
		}
	}
	
	/* postavi submarine */
	if (rand()%2 == 0) {
	  postavisubmarinevodoravnokomp:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_SUBMARINE);
		pom = 0;
		for (j = stup; j < stup + D_SUBMARINE; j++) {
			pom += matkomp[red][j];
		}
		if (stup+D_SUBMARINE < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_SUBMARINE; j++) {
				matkomp[red][j] = 1;
			}
		} else {
			goto postavisubmarinevodoravnokomp;
		}
	}	else {
	  postavisubmarineokomitokomp:
		red = rand()%(BRRED-D_SUBMARINE);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_SUBMARINE; i++) {
			pom += matkomp[i][stup];
		}
		if (red+D_SUBMARINE < BRRED && pom == 0) {
			for (i = red; i < red + D_SUBMARINE; i++) {
				matkomp[i][stup] = 1;
			}
		} else {
			goto postavisubmarineokomitokomp;
		}
	}
	
	/* postavi destroyer */
	if (rand()%2 == 0) {
	  postavidestroyervodoravnokomp:
		red = rand()%BRRED;
		stup = rand()%(BRSTUP-D_DESTROYER);
		pom = 0;
		for (j = stup; j < stup + D_DESTROYER; j++) {
			pom += matkomp[red][j];
		}
		if (stup+D_DESTROYER < BRSTUP && pom == 0) {
			for (j = stup; j < stup + D_DESTROYER; j++) {
				matkomp[red][j] = 1;
			}
		} else {
			goto postavidestroyervodoravnokomp;
		}
	}	else {
	  postavidestroyerokomitokomp:
		red = rand()%(BRRED-D_DESTROYER);
		stup = rand()%BRSTUP;
		pom = 0;
		for (i = red; i < red + D_DESTROYER; i++) {
			pom += matkomp[i][stup];
		}
		if (red+D_DESTROYER < BRRED && pom == 0) {
			for (i = red; i < red + D_DESTROYER; i++) {
				matkomp[i][stup] = 1;
			}
		} else {
			goto postavidestroyerokomitokomp;
		}
	}
	}
	
	/* na pocetku isprintaj plocu*/
	if (3) {
	printf ("\n  _____   ____ _______       _____        _   _      _ ______ \n");
	printf (" |  __ \\ / __ \\__   __|/\\   |  __ \\ /\\   | \\ | |    | |  ____|\n");
	printf (" | |__) | |  | | | |  /  \\  | |__) /  \\  |  \\| |    | | |__   \n");
	printf (" |  ___/| |  | | | | / /\\ \\ |  ___/ /\\ \\ |   ` |_   | |  __|  \n");
	printf (" | |    | |__| | | |/ ____ \\| |  / ____ \\| |\\  | |__| | |____ \n");
	printf (" |_|__  _\\____/ _|_/_/____\\_\\_|_/_/_   \\_\\_| \\_|\\____/|______|\n");
	printf (" |  _ \\|  __ \\ / __ \\|  __ \\ / __ \\ \\    / /\\     \n");
	printf (" | |_) | |__) | |  | | |  | | |  | \\ \\  / /  \\    \n");
	printf (" |  _ <|  _  /| |  | | |  | | |  | |\\ \\/ / /\\ \\   \n");
	printf (" | |_) | | \\ \\| |__| | |__| | |__| | \\  / ____ \\  \n");
	printf (" |____/|_|  \\_\\\\____/|_____/ \\____/   \\/_/    \\_\\ \n\n");
	printf ("Upute:\n");
	printf ("Aj ne seri valjda znas igrati ovo\n");
	


		printf ("\n       Igraceva ploca          Protivnikova ploca\n");
		printf ("\n     A B C D E F G H I J       A B C D E F G H I J \n ");
		for (i = 0; i < BRRED; i++) {
			printf ("%2d. ", i+1);
			for (j = 0; j < BRSTUP; j++) {
				if (matigrac[i][j] == 0) {
					printf ("~ ");
				} else if (matigrac [i][j] > 0) {
					printf ("%d ", matigrac[i][j]);
				} else if (matigrac[i][j] == -1) {
					printf ("X ");
				} else if (matigrac[i][j] == -2) {
					printf ("O ");
				}
				if (matigrac[i][j] == -1) {
				brojbodovaigrac++;
				}
				if (matkomp[i][j] == -1) {
				brojbodovakomp++;
				}
			}
			printf ("  %2d. ", i+1);
			for (j = 0; j < BRSTUP; j++) {
				if (matkomp[i][j] >= 0) {
					printf ("~ ");
				} else if (matkomp[i][j] == -1) {
					printf ("X ");
				} else if (matkomp[i][j] == -2) {
					printf ("O ");
				}
			}
			printf ("\n ");
		}
		
		printf ("\nLegenda: X - pogoden brod, 0 - promasen brod, ~ - neistrazeno\n");
	}
	
	/* igraj */
	do {
		brojrundi++;
		brojbodovaigrac = 0;
		brojbodovakomp = 0;
		
		/* igracev potez */
		/* -1 oznacava da je tu bio brod koji je pogoden 
		   -2 oznacava da je polje vec isprobano i da na njemu nije bilo broda */
			do {	
			  upisiigrac:
				printf ("\nUpisi koordinate koje zelis napasti (x y) > ");
				scanf ("%c%d", &pom2, &i);
				i--;
				if (pom2 >= 'A' && pom2 <= 'J') {
					j = pom2 - 'A';
				} else if (pom2 >= 'a' && pom2 <= 'j') {
					j = pom2 - 'a';
				}
				
				if (i >= BRRED || i < 0 || j >= BRSTUP || j < 0) {
					printf ("\nNeispravne koordinate\n");
					goto upisiigrac;
				}
				if (matkomp[i][j] == 1) {
					printf ("\nPogodak\n");
					matkomp[i][j] = -1;
				} else if (matkomp[i][j] == 0) {
					printf ("\nPromasaj\n");
					matkomp[i][j] = -2;
				} else {
					printf ("\nKretenu vec si probao ovo polje\n");
					goto upisiigrac;
				}
			/* mozda izmijeni na -1 i -2 nisam siguran */
			} while (matkomp[i][j] >= 0 && igragotova == 0);
			
			printf ("\n\n%d %d\n\n", i, j);

		/* kompov potez, ako se ikad vratis umetni bolji ai 
		   objasnjenje ai: 
		   ako je pogodak nula onda generira novi set koordinata
		   ako je pogodak jedan onda pokusava ici po susjednim poljima
		   i trazi je li tamo mozda pogodak jedan 
		    ^ ne da mi se ovo pisati samo cu staviti neka randomly gada */
			do {
			  upisikomp:
				i = rand()%10;
				j = rand()%10;
				
				if (matigrac[i][j] < 0) {
						goto upisikomp;
					} else if (matigrac[i][j] > 0) {
						matigrac[i][j] = -1; 
					} else if (matigrac[i][j] == 0) {
						matigrac[i][j] = -2;
					} else {
						printf ("IDK %d\n", matigrac[i][j]);
					}
				
			} while (matigrac[i][j] >= 0 && igragotova == 0); 
		
		/* ispisi igracevu plocu i plocu kompa koju i nastavi igru ako nije gotova*/
	if (4) {
		printf ("\n       Igraceva ploca          Protivnikova ploca\n");
		printf ("\n     A B C D E F G H I J       A B C D E F G H I J \n ");
		for (i = 0; i < BRRED; i++) {
			printf ("%2d. ", i+1);
			for (j = 0; j < BRSTUP; j++) {
				if (matigrac[i][j] == 0) {
					printf ("~ ");
				} else if (matigrac [i][j] > 0) {
					printf ("%d ", matigrac[i][j]);
				} else if (matigrac[i][j] == -1) {
					printf ("X ");
				} else if (matigrac[i][j] == -2) {
					printf ("O ");
				}
				if (matigrac[i][j] == -1) {
				brojbodovaigrac++;
				}
				if (matkomp[i][j] == -1) {
				brojbodovakomp++;
				}
			}
			printf ("  %2d. ", i+1);
			for (j = 0; j < BRSTUP; j++) {
				if (matkomp[i][j] >= 0) {
					printf ("~ ");
				} else if (matkomp[i][j] == -1) {
					printf ("X ");
				} else if (matkomp[i][j] == -2) {
					printf ("O ");
				}
			}
			printf ("\n ");
		}
		
		printf ("\nLegenda: X - pogoden brod, 0 - promasen brod, ~ - neistrazeno\n");
		
		pom = D_BATTLESHIP + D_CARRIER + D_CRUISER + D_SUBMARINE + D_DESTROYER;
		if (brojbodovaigrac == pom || brojbodovakomp == pom) {
			igragotova = 1;
		}
	}
	} while (igragotova == 0);
	
	/* prikazi tko je pobijedio i s koliko bodova */
	if (brojbodovakomp == pom) {
	printf ("\nPobijedio je igrac s %d bodova u %d rundi",brojbodovakomp, brojrundi);
	} else if (brojbodovaigrac == pom) {
	printf ("\nPobijedio je komp s %d bodova u %d rundi",brojbodovaigrac, brojrundi);
	} else {
		printf ("\nIdk sta se dogodilo, mozda je izjednaceno (%d rundi)", brojrundi);
	}
	printf ("\n	   (MAX %d bodova)", pom);
	return 0;
}