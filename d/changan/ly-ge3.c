// Room: /d/changan/ly-ge3.c

#include <ansi.h>
inherit ROOM;

protected string ldesc = 0;

string query_long();
protected void init_long();

void create()
{
	set("short", "���̸�����");
/*
	set("long", @LONG
�����¡�һ����ʿ��
LONG
	);
*/
	set("long", (: query_long :));

	set(SAFE_ENV,1);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"ly-ge2",
  //"up" : __DIR__"ly-ge4",
]));

/*
	set("objects",([
		"/obj/paiming/one" : 1,
		"/obj/paiming/two" : 1,
		"/obj/paiming/three" : 1,
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
	string *titles = allocate(3), bk = "", end;
	int len;

	for(int i=0; i<3; i++)
	{
		string name, id, tl;
		int exp, age, male;

		if(!PAIMING_D->query_player_data(i+1, ref name, ref id, ref tl, ref exp, ref male, ref age)
		|| !id )
			titles[i] = sprintf("�����µ�%s��[��ȱ]",chinese_number(i+1));
		else
			titles[i] = sprintf("�����µ�%s��%s %s(%s)",
				chinese_number(i+1), tl, name, capitalize(id));

		if(len < sizeof(titles[i]))
			len = sizeof(titles[i]);
	}

	//len += 2;
	if(len%2)
		len++;

	ldesc = sprintf(HIY BWHT"\n%|"+(string)(len+4)+"s\n%|"+(string)(len+4)+"s\n�X","�� ����һ����ʿ�� ��","��������������������������");

	for(int i=0;i<len/2;i++)
		bk += "�T";

	ldesc += sprintf("%s�[\n",bk);

	end =  sprintf("�^%s�a%s\n\n",bk,NOR);

	for(int i=0;i<3;i++)
		ldesc += sprintf("�U%-"+(string)len+"s�U\n",titles[i]);

	ldesc += end;
}

