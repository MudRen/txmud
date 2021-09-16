// dizi7.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("̤ѩ���", ({ "taxue qiuchan", "qiuchan","girl"}));
	set("class","taxue");
	set("nickname", HIC"֪������"NOR);
        create_family("̤ѩɽׯ", 2, "����");
        set("gender", "Ů��");
	set(NO_KILL,1);
        set("age", 20);
        set("attitude","friendly");
	set("long", "����ׯ��̤ѩ��Զ�Ķ���Ů�������ü�Ϊ��ò,һ˫�۾��������ԡ�\n��������С������ѧ���ֵ���ʦָ�㣬����������֪���������еĹ���\n");

        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("no_get",1);
        set("per", 30);
        set("max_kee", 4000);
        set("max_gin", 4000);
        set("force", 4000);
        set("max_force", 4000);
        set("max_atman", 4000);
        set("max_mana", 4000);

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

void init()
{
        add_action("lingwu","ask");
}

int lingwu(string arg)
{
	int bl,sl,bonus;
        object me,ob,where;
        string special,name;

	ob = this_object();
	me=this_player();
	where = environment(me);

        if (!arg) return 0;
        if (!sscanf(arg, "%s about %s", name, arg)) return 0;
        if (!id(name)) return 0;

        write( "����̤ѩ�����̹��ڡ�" + to_chinese(arg) + "�������ʡ�\n");
        if (me->is_busy() || me->is_fighting()) {
                command("say ����æ���ء�");
                return 1;
        }

        if (!(special=me->query_skill_mapped(arg))) {
                if (arg == to_chinese(arg))
                        command("say ��" + arg + "����ʲô�书����ô��û��˵����");
                else
                        command("say ��ֻ�ܴ�������⼼���и���ָ�㡣");
                return 1;
        }
        if (!me->query_skill(arg,1)) {
                command("say �㲻�����ּ��ܡ�");
                return 1;
        }

        if((int)me->query("potential", 1) < 1 ) 
                return notify_fail("���ʵս�еõ���Ǳ���Ѿ������ˡ�\n");

        bl=me->query_skill(arg,1);
        if (me->query("gin")*100/me->query("max_gin") < 50) {
                me->receive_damage("gin",bl/20);
                command("say " + RANK_D->query_respect(me) + "����Ϣһ�°ɡ�");
                return 1;
        }

        if (bl > 350) {
                command("say " + RANK_D->query_respect(me) + "�Ļ���"+to_chinese(arg)+"�Ѿ������ˣ���Ҳ����ָ����ʲô��");
                return 1;
        }

        sl=me->query_skill(special,1);
        if (bl > sl) {
                command("say " + RANK_D->query_respect(me) + "��"+to_chinese(special)+"���費�����Ҳ���ָ�������һ���"+CHINESE_D->chinese(arg)+"��");
                return 1;
        }
        write("������" + name() + "��ָ�㣬��"+to_chinese(arg)+"�����������һ�㡣\n");
        me->receive_damage("gin",bl/20);
        me->add("potential", -random(2));
        bonus =((me->query("int") +me->query_skill("literate")/10)* 10 /3)+10;
        me->improve_skill(arg, bonus);
        return 1;
}