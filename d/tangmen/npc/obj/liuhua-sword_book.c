inherit ITEM;

void create()
{
       set_name("������Ӱ����", ({ "liuhua-sword book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"�Ȿ������ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
"д����һЩ������ľ���̸֮ʲô�á�\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "liuhua-sword", // �书����,
        "exp_required": 5000,    // ��������Ҫ����;���.
        "sen_cost":     15,      // ���黨����.
        "difficulty":   25,      // �ο� /cmds/std/study.c
        "max_skill":    40,      // �ܶ�������ߵȼ�.
]) );
        }
}
int is_tangmen_book() { return 1; }

