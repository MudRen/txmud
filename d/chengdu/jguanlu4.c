// Room: /wiz/louth/c/jguanlu4.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ��Ľ���·����������������һֱ�����ߵ�����·��
���Ͼ��ǳɶ��ķ�ľ���������ǳɶ�������Ĺ���򶫿��Դ�����
��������ʮ��·�ںͽ���·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wjmu",
  "east" : __DIR__"jguanlu3",
  "north" : __DIR__"wwdao5",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
