// Room: /u/w/wangs/b/kai36.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ſڹ���һ�Ų�������������ɰд�š����忾�⡱�ĸ���
�֣����ƿ��������˽�����һ�����˵���֬����������ʳָ�󶯣�
�����ʮ�����������������ģ�ֱ�����ŵĵط�֧��������¯��
�������һ�鱻�յ÷�������壬����Ļ���ڰ����Ϸɿ�ذ�
һ�������Ƭ�ɰ��ư��С���ӽ����Ϲ������һ�����㵹����
�����յ�֨֨���졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai64",
  "west" : __DIR__"kai34",
]));
        set("objects",([
        __DIR__"npc/rouboss" : 1,
]));

	setup();
	replace_program(ROOM);
}