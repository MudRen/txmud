// /d/tianshui/duchang.c

inherit DUCHANG;

void create()
{
        set("short", "��ˮ�Ĺ�");
        set("long", @LONG
�������Զ����������ˮ�Ĺݡ��������˷��Ľк�������
�ӡ�Ԫ��������������ײ��ʹ��Ҳ����ѪҺ��������������Ҳ��
(bet)�����������������űߵ�����(paizi)д������ĶĹ档��
����¥��ͨ���¥��
LONG
        );
        set("item_desc", ([
                "paizi" : 
"\n���ĳ�Ŀǰ����Ѻ����С��,��������:\n"
"�������ӵ����ܺͣ�\n"
"       ��   �� ʮ   Ϊ��С��(small)��\n"
"       ʮһ �� ʮ�� Ϊ����(big)��\n"
"��Ҳ����Ѻȫɫ (all) ���������ӵ�����ͬ��\n"
"����Ѻ�Ľ��������ҡ���Ľ����ͬ����һ��һ��\n"
"����ѺȫɫѺ������һ��ˣ�Ѻ100��Ӯ800����\n\n"
"���ĳ�ֻ��������Ϊ��ע,���ٲ��ޡ�\n",
        ]));
        set("exits", ([
                "west" : __DIR__"nroad2",
		  "up" : __DIR__"duchang2"
                     ]));
	set("objects",([
	__DIR__"npc/judge" : 1,
]));
        set(SAFE_ENV,1);
        setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "up")
		return notify_fail("ͨ��¥�ϵ��Ž����ţ���ʱ����������Լ�Ľк�����¥�Ϻ���Ҳ�ڶ�Ǯ��\n");
	return ::valid_leave(me,dir);
}
