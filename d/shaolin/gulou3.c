// Room: /d/shaolin/gulou3.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�����������µĹ�¥���㣬������߹���Ҳ��������������
��ɴ�¥�Ե�С����������Ŀ��������µ�ȫò��Ҳ���Խ��Ż�
���Ĺ⿴���¥ǽ���ϻ��ŵĸ��ֹ��ϵıڻ�����������¥����
�����ǹ�¥���㣬�����ǹ�¥�Ķ�¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"gulou2",
  "up" : __DIR__"gulou4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
