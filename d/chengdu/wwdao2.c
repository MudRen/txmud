// Room: /wiz/louth/c/wwdao2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ����������������������Ǵ�����ݡ��򶫾��Ǻͼ�
Ǯׯ���ϱ�������Թ�ͨ������������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wuguan",
  "south" : __DIR__"wwdao3",
  "east" : __DIR__"qianzhuang",
  "north" : __DIR__"wwdao1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
