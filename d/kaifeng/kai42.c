// Room: /u/w/wangs/b/kai42.c

inherit ROOM;

void create()
{
	set("short", "��֬��");
	set("long", @LONG
�����ר��Ů���õ���֬ˮ�۵�һ�ҵ��̣�������ɫ���޵�
��ױƷ��ɫ֮�����ǲ���˵�ˣ�������������עĿ�ľ��������
�ϰ����ˣ������Ļ�֦��չ������ȥֻ�ж�ʮ��������ӣ���
�Ǿ���˵���������Ѿ���ʮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai40",
]));

        set("objects",([
        __DIR__"npc/bossniang" : 1,
]));

	setup();
	replace_program(ROOM);
}
