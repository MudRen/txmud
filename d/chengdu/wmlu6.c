// Room: /wiz/louth/c/wmlu6.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·������һ��˽լ���ſڰ�������Сʯ
ʨ�ӣ��������Ǹ������ٵ����𡣶�������Թᴩ��������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu7",
  "east" : __DIR__"wmlu5",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_3" : 3,
]));

	setup();
	replace_program(ROOM);
}
