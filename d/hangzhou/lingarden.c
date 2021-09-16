// Room: /d/hangzhou/lingarden.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�������ּҵĺ�԰�����������Ѿ����Ӳݴ�������ľ����
Ӧ���Ǻܾ�û���˴����ˣ���԰�Ľ�����һ��һ�˶�ߵļ�ɽ��
�Ա߻���һ��ˮ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"linmishi",
  "west" : __DIR__"linpath3",
]));
	set("outdoors", "hangzhou");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
