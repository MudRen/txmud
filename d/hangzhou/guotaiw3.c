// Room: /d/hangzhou/guotaiw3.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����Ǻ����������һ���֣����ݸ���֪�����ž���������
�����ϣ��������·�ϵ�����Ҳ�Ƚ��٣����⣬������ϱ���
��Զ�ھ�Ҳ�������������ϡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yongning",
  "south" : __DIR__"weaponshop",
  "east" : __DIR__"guotaiw2",
  "north" : __DIR__"chaguan",
]));

	setup();
	replace_program(ROOM);
}
