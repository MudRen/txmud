// Room: /d/fengtian/mofang.c

inherit ROOM;

void create()
{
	set("short", "ĥ��");
	set("long", @LONG
����һ���ϵ��ˣ�����ĥ���Ķ�����ȫ���춼������������
�������ĵط����ǵ��ꡰ����󽫾���ս��ɳ����ĥ�������
���Ǯ��أ���ĥ�����潨��һ������������ġ�������������
���조���������������ˣ�����ĥ��Ҳ��Ϊ������ϰ徭Ӫ��
�����������ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
