// Room: /wiz/louth/c/chaguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����ǳɶ�������ݡ�����ÿ�춼�ɲ�ͬ����Ĳ裬���ɶ�
��ѿ���ɶ�ʯ������üë�塢���ȸ�ࡢ��׼⹦����������
�򻨲趼�У������һ�ߺȲ�һ�����졣�ɶ�ƽ���ݲ��������
�ģ�����������˿�ӯ�ž��ܿ�������������ž�������·��
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wmlu2",
]));
        set("objects",([
        __DIR__"npc/chunxier" : 1,
]));
	setup();
	replace_program(ROOM);
}
