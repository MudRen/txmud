// Room: /u/w/wangs/b/kai124.c

inherit ROOM;

void create()
{
	set("short", "�÷��");
	set("long", @LONG
Ҫ˵��Ҳ÷�����ʷ�ɾͳ��ˡ����ƹ��үү��үү��ү
ү��ʼ�������ˡ��÷����ϰ廹�Ǹ�����ˣ����Ӱ���һ��ͬ
�ʡ������ڿ�����ﲻ֪�����������ү��ʲô���У�����֪��
�÷����Ҳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai122",
]));

        set("objects",([
        __DIR__"npc/zhangdama" : 1,
]));

	setup();
	replace_program(ROOM);
}
