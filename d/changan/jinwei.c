// Room: /d/changan/jinwei.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
�����������ʹ��Ľ�����פ���ĵط������ӹٱ����ڲٳ���
��������Զ�ĵط���ʮ��Ӫ������������ţ����治Զ�ĵط���
�������ˡ��㿴���м���������ɫ���Ƶض���ָָ��㣬����
������մ�˵�Ϊ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuma",
  "north" : __DIR__"shroad3",
]));

	setup();
	replace_program(ROOM);
}
