// Room: /d/hangzhou/fishshop.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�䲻̫�����꣬һ���ţ���Ϳ�����ǽ�Ϲ���һ��
��������ѩ��ˮīɽˮ�������ϰ岻���ǻ������⣬����һλ��
ѧ֮ʿ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guotaie1",
]));

	setup();
	replace_program(ROOM);
}
