// Room: /wiz/louth/c/yangmalang.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǳɶ��������ȡ��ɶ�����Ա����ƥ���Ǵ�������ѡ
�ġ����������߾��ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu5",
]));
        set("objects",([
        __DIR__"npc/mafanzi" : 1,
]));

	setup();
	replace_program(ROOM);
}
