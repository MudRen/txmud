// Room: /wiz/louth/c/wmlu3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·�����������Ͼ��ǰ����̡������Ͼ�
�����۵ꡣ������������Թᴩ��������·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu4",
  "east" : __DIR__"wmlu2",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
