// Room: /d/hangzhou/stree2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ��ݳ����һƬ���֣�����С���ڲ�ͣ��ߴ�У��·���
���㰵ʾ��ʲô���������ϡϡ������һ����֪������̤���Ľ�
���������Ǻ��ݳ���Ļ��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"spath2",
]));
	set("outdoors", "hangzhou");
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_6" : 6,
]));


	setup();
	replace_program(ROOM);
}
