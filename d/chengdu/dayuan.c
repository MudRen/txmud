// Room: /wiz/louth/c/dayuan.c

inherit ROOM;

void create()
{
	set("short", "�ƾɴ�Ժ");
	set("long", @LONG
����һ���ưܲ�����Ժ�䣬���ϳ�������ݣ���Χ�ķ��ݴ�
�����Ѿ������ˣ�ֻ�ж�����һ��С���ݡ��ݴ��к������˵ĵ�
�ż���������������Լ�ܿ�������ž����Ļ��ƣ��·�����˵��
�������յĻԻ͡�����ǣ�ª�ҿ��ã�������������˥�ݿ��
��Ϊ���賡��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaowu",
  "north" : __DIR__"pixiang",
]));

	setup();
	replace_program(ROOM);
}
