// Room: /d/huanggong/yangxd.c

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
�����ǻʵ�����˼����Ϣ�ĵط�����̺�̵أ�һ��������
����һЩ���ġ�������¯�������ð������....��ǽ��һ������
�����ĸ��پ��Ĵ��֡�����ֹˮ����һ�߽��������һ�־�����
�µĸо���һ�з��ﶼ��ʧ����Ӱ���ۣ�һ�־���֮�µĸо���
����ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"longzm",
  "north" : __DIR__"donggdm",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}