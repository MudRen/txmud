// Room: /u/w/wangs/b/kai66.c

inherit DUCHANG;

void create()
{
	set("short", "�����ĳ�");
	set("long", @LONG
��ҹ��Ϩ������յ�����յ������˺����֣����־�ζ����ζ��
Ů�����ϵ��ٻ���ζ������ɫ�ӹ�������������ײ������ͽ�ĺ�
�����д̼�����ѪҺ���ڣ��㼷��һ����ǰ���ͳ��������е�Ǯ
������һ�ڣ���������������󣡡�����Χ���˺�Ц�������ű�
������(paizi)д������ĶĹ档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai65",
]));

	set("item_desc", ([
		"paizi" : 
"\n���ĳ�Ŀǰ����Ѻ(bet)����С��,��������:\n"
"�������ӵ����ܺͣ�\n"
"       ��   �� ʮ   Ϊ��С��(small)��\n"
"       ʮһ �� ʮ�� Ϊ����(big)��\n"
"��Ҳ����Ѻȫɫ (all) ���������ӵ�����ͬ��\n"
"����Ѻ�Ľ��������ҡ���Ľ����ͬ����һ��һ��\n"
"����ѺȫɫѺ������һ��ˣ�Ѻ100��Ӯ800����\n\n"
"���ĳ�ֻ��������Ϊ��ע,���ٲ��ޡ�\n",
        ]));

        set("objects",([
        __DIR__"npc/dutu1": 2,
        __DIR__"npc/zhangl": 1,
]));

	setup();
}