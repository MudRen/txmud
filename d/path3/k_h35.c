// Room: /d/path3/k_h35.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������¡���˵�����ն����ڴˣ�����Ů���ֹ�����
�ľ������Ҷ�������������������������ĺ��񲻶��ˡ�������
һƬ���֣��ֱ�����һ�����ӡ�
LONG
	);
        set("item_desc",([
          "����":"
                  northwest    �����ɿ�
                  south        ���ݳ� \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h36",
  "northwest" : __DIR__"k_h34",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 3,
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
