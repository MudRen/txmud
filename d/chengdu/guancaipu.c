// Room: /wiz/louth/c/guancaipu.c

inherit ROOM;

void create()
{
	set("short", "�ײ���");
	set("long", @LONG
�����ǳɶ��Ĺײ��̡�������˺ܶ�յĹײģ��ײ��̵���
���������⣬�ƺ��ڵ����µ��������š������뿪���ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu3",
]));
        set("objects",([
        __DIR__"npc/wuboss" : 1,
]));


	setup();
	replace_program(ROOM);
}
