// Room: /d/shaolin/lroad5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µش���Ժ�Ĺ�������������˺��٣���������
�ľ���ȴ��������Զ���м��Ű�С�Ĺ�ľ�����ľ���С����ӳ��
Ȥ��żȻ����һ����������Ľ���������ʹ�����ˣ�����ǧ���
ɲ�������������ǵز�����������䳡���ϱ��ǹ���������
���������µĺ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lroad4",
  "east" : __DIR__"yanwu",
  "west" : __DIR__"dizang",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
