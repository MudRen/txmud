// Room: /u/w/wangs/b/kai132.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������ǿ���ǵ������Ӿ۵ĳ��������ص����������ﶼ
����Ʒ���������ķ���Ҳ��ȫ������ġ����������İ���
һЩ���Σ������һ��Ʒ�裬һ�߻�����ɫ��ͷ�Ӷ������ۣ���
�����С�����ľ�������һЩ��Ϊ��֪��С����Ϣ����཭����
ʿ�����������̽��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai131",
]));
        set("objects",([
        __DIR__"npc/cboss": 1,
]));

	setup();
	replace_program(ROOM);
}
