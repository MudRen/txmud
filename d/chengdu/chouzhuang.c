// Room: /wiz/louth/c/chouzhuang.c

inherit ROOM;

void create()
{
	set("short", "��ǳ�ׯ");
	set("long", @LONG
������������������������ǳ�ׯ���������Ĵ�����֮һ��
��ʷ�ƾá������뷨�Ͻ������弼�ն��أ�Ƭǳ������ɫ�����죬
����Ũ��ĵط�ɫ�ʡ�������������ġ�ܽ�����㡷�ȡ�ÿ���
�۶���Ҫ����ǳ�ׯ�����������ϵ����壬�ɼ����ֵ���ڣ���
��ǳ�ׯ�ı����ž�����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu7",
]));

	setup();
	replace_program(ROOM);
}
