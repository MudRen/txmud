// Room: /d/path1/tch_ft1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�ı�����һ������ɽ����������ƬƬ
�����֡�����������㲻���е��������⡣���治Զ���ǡ�����
�¡��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cc_tch16",
  "east" : __DIR__"tch_ft2",
]));
	set("outdoors", "path1");
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 4,
]));

	setup();
	replace_program(ROOM);
}
