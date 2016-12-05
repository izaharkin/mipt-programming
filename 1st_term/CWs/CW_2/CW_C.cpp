int check (struct Card* hand)
{
	int cnt[4] = {0};
	
	for (struct Card* p = hand; p->rank != 0; p++)
		for (int i = 0; i < 4; i++)
			if ( p->suit == suit[i] )
				cnt[i]++;
	
	for (int i = 0; i < 4; i++)
		if ( cnt[i] >= 5 )
			return 1;
	
	return 0;
}
