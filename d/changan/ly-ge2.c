// Room: /d/changan/ly-ge2.c

#include <ansi.h>
inherit ROOM;

protected string ldesc = 0;

string query_long();
protected void init_long();

void create()
{
	set("short", "���̸����");
/*
	set("long", @LONG
�����¡�������ʿ��
LONG
	);
*/

	set("long", (: query_long :));
	set(SAFE_ENV,1);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"ly-ge",
  "up" : __DIR__"ly-ge3",
]));
/*
	set("objects",([
		"/obj/paiming/four" : 1,
		"/obj/paiming/five" : 1,
		"/obj/paiming/six" : 1,
		"/obj/paiming/seven" : 1,
		"/obj/paiming/eight" : 1,
		"/obj/paiming/nine" : 1,
		"/obj/paiming/ten" : 1,
]));
*/
	setup();
}

string query_long()
{
	if(!ldesc)
		init_long();

	return ldesc;
}

protected void init_long()
{
	string *titles = allocate(7), bk = "", end;
	int len;

	for(int i=0; i<7; i++)
	{
		string name, id, tl;
		int exp, age, male;

		if(!PAIMING_D->query_player_data(i+4, ref name, ref id, ref tl, ref exp, ref male, ref age)
		|| !id )
			titles[i] = sprintf("�����µ�%s��[��ȱ]",chinese_number(i+4));
		else
			titles[i] = sprintf("�����µ�%s��%s %s(%s)",
				chinese_number(i+4), tl, name, capitalize(id));

		if(len < sizeof(titles[i]))
			len = sizeof(titles[i]);
	}

	if(len%2)
		len++;

	ldesc = sprintf(HIW BWHT"\n%|"+(string)(len+4)+"s\n%|"+(string)(len+4)+"s\n�X","�� ���¶�����ʿ�� ��","��������������������������");

	for(int i=0;i<len/2;i++)
		bk += "�T";

	ldesc += sprintf("%s�[\n",bk);

	end =  sprintf("�^%s�a%s\n\n",bk,NOR);

	for(int i=0;i<7;i++)
		ldesc += sprintf("�U%-"+(string)len+"s�U\n",titles[i]);

	ldesc += end;
}

