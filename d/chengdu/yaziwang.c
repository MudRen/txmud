// Room: /wiz/louth/c/yaziwang.c

inherit ROOM;

void create()
{
	set("short", "Ѽ����");
	set("long", @LONG
�����ǳɶ�������Ѽ������Ѽ�ꡣ�ӳɶ������죬���ϵر�
�ĸ�ʽ��Ѽ���С�����Ѽ������Ѽ��������Ѽ�ӡ��ȵ�����ʤ����
ÿ���������˳Կ�Ѽ�������ﲻ�����ӿ�Ѽ������ų���������
��·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wmlu1",
]));
        set("objects",([
        __DIR__"npc/wangboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
