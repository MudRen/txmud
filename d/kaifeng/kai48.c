// Room: /u/w/wangs/b/kai48.c

inherit ROOM;

void create()
{
	set("short", "ϷԺ");
	set("long", @LONG
̨�ϼ������˴����������ò����֣��������˿���ԭ����
һ��������ɽ����̨��ʮ��̫�����Ŀյ���Χ������Ϸ��Ⱥ�ڡ�
��˵Ҳ��������ˣ�������ϷԺ�г��˳�Ϸ���⣬��Ⱥ��û�з�
��һ���������ɼ�������ú�ר�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai47",
]));
        set("objects",([
        __DIR__"npc/ximi":3,
]));

	setup();
	replace_program(ROOM);
}
