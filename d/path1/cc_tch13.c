// Room: /d/path1/cc_tch13.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������·��·�ϵ�����������Խ��Խ���ˣ�ż����
�������˾�������һ�������㲻���е��̵�������·��������һ
ƬƬ�����֣��ּ䲻ʱ����������С�
LONG
	);
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 3,
]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch12",
  "north" : __DIR__"cc_tch14",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}