

bool czyJestDwucykliczny(string binarnyCiag)

bool czyJestWiekszaOd9(string binarnyCiag)

bool czyJestPoprawna(string binarnyCiag)

int konwersjaNaDziesietne(string binarnyCiag)


int main()
{
	
	while
	{
		
		plik >> s
		
		//1
		if(czyJestDwucykliczna(s))
			++licznikDwucyklicznych
			// tutaj dodatkowo umieszczamy szukanie dlugosci najdluzszej dwucyklicznej
		//2
		if(czyJestPoprawna(s))
			++licznikNiepoprawnych
			// tutaj dodatkowo umieszczamy szukanie dlugosci najkrótszej niepoprawnej
		//3
		if(s.length() <= 16)
			if(konwersjaNaDziesietne(s) > max)
				max = s;
			// na koncu potrzebujemy jeszcze policzyc wersje dziesietna max
	}
	return 0;
}
