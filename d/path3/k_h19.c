// Room: /d/path3/k_h19.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ţͷɽɽ�ţ�ɽ�������Ķ����ƺ����������档·��
����������ʲô���ˣ��㲻���첽��ǰ��������һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h20",
  "northwest" : __DIR__"k_h18",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
