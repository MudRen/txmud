// Room: /d/path3/k_s5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һƬ���֣�����һ��С·������ǰ����ʱ����������
�У��ֲ�����ʲô����㲻�ɵüӿ��˽Ų����ɴ���˾͵�פ
����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s6",
  "north" : __DIR__"k_s4",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
