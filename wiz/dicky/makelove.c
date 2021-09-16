// sleep.c

#include <ansi.h>
#include <command.h>

void do_makelove(object me, object target);
void do_loving(object me, object target, int wakeup);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string no_tell;
        object target;
        object where = environment(me);

        seteuid(getuid());

        if (! (where->query("sleep_room"))
             || (where->query("no_sleep_room")))
                return notify_fail("���������ɲ�̫�ã��Ҹ���ȫ��ĵط��ɣ�\n");

        if (! arg || ! objectp(target = present(arg, where)))
                return notify_fail("�����˭������\n");

        if (! target->is_character() || target->query("not_living"))
                return notify_fail("������ˣ��ǲ��ǻ��ˣ�\n");

        if (! target->query("can_speak"))
                return notify_fail("����ˣ����" + target->name() + "�Խ���\n");

        if (me == target)
                return notify_fail("���Լ�Ҫ���Լ�...�㻹�ǿ�ؼ��Լ��о��ɡ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�߶��ֱ����������Ȼ���д��⣡\n");

        if (! userp(target))
                return notify_fail(target->name() + "һ�ţ�ŭ�����㡣(���Ǳ����˼���)\n");

        if (me->query("gender") == "����")
                return notify_fail("�����˶���ģ���˻������£������ټ���\n");

        if (me->query("gender") == target->query("gender"))
                return notify_fail("ͬ����ô...�����Լ��ú��о���ôŪ�ɣ�����ָ�̫���ʡ�\n");

     /*   if (me->query("age") < 16)
                return notify_fail("�㻹û�з�����ȫ���������£�\n");*/

        if (me->query_temp("pending/makelove") == target)
                return notify_fail("���Ѿ���������Ҫ���ˣ������˼һ�û�д�Ӧ�㡣\n");

        if (me->query("gin") * 100 / me->query("max_gin") < 80)
                return notify_fail("��ľ��񲻼ã�����û���������˼�������\n");

        if (me->query("kee") * 100 / me->query("max_kee") < 60)
                return notify_fail("���������֧������û���������˼�������\n");

        if (me->query("gender") == "����" &&
            time() - (int)me->query_temp("last_makelove") < 120)
                return notify_fail("������������������û������һ�Ρ�\n");

        no_tell = target->query("env/no_tell");
	if (no_tell == "all" || no_tell == "ALL")
		return notify_fail("����˲���������������\n");

        if (target->query_temp("pending/makelove") == me)
        {
                target->delete_temp("pending/makelove");
                do_makelove(me, target);
                return 1;
        }

        me->set_temp("pending/makelove", target);
        message("vision", me->name() + "���ĵĺ�" + target->name() + "˵�˼��仰��\n",
                environment(me), ({ me, target }));
        if (me->query("gender") == "����")
        {
                me->force_me("tell " + target->query("id") +
                             " �ñ���������ͺ��һ���һ�ΰɡ�");
        } else
        {
                me->force_me("tell " + target->query("id") +
                            " ��������Ҫ��ô��");
        }

        return 1;
}

void do_makelove(object me, object target)
{
        mapping armor;
        string msg;
        string msg1, msg2;
        object man, woman;

        if (me->query("gender") == "����")
        {
                man = me;
                woman = target;
        } else
        {
                man = target;
                woman = me;
        }

        if (armor = me->query_temp("armor") && sizeof(armor))
                me->force_me("remove all");

        if (armor = target->query_temp("armor") && sizeof(armor))
                target->force_me("remove all");

        msg = "$N�����§��$n��˫�ִ�$n�����������ĸ�����ȥֱ�����ţ�ֻ��$p"
              "���ɵĲ�����һ�£�һʱ���������ԣ�˫�ֽ����ı�ס��$N��������"
              "�������$N�Ļ��У�ĥ����$P���ؿڣ���ʱ�����ô��⣬���������"
              "�������˽����Ľ��������ҵ�״̬��";
        msg1 = replace_string(msg, "$N", "��");
        msg1 = replace_string(msg1, "$n", woman->name());
        msg1 = replace_string(msg1, "$P", "��");
        msg1 = replace_string(msg1, "$p", "��");

        msg2 = replace_string(msg, "$N", man->name());
        msg2 = replace_string(msg2, "$n", "��");
        msg2 = replace_string(msg2, "$P", "��");
        msg2 = replace_string(msg2, "$p", "��");

        msg = replace_string(msg, "$N", man->name());
        msg = replace_string(msg, "$n", woman->name());
        msg = replace_string(msg, "$P", "��");
        msg = replace_string(msg, "$p", "��");

        message("vision", msg1, man);
        message("vision", msg2, woman);
        message("vision", msg, environment(man), ({ man, woman }));

        tell_object(man, HIR "\n�����鼤������Ѫ���ڣ�һʱ�����Լ�...\n" NOR);
        tell_object(woman, HIR "\n������һ�����������ԣ������Լ�...\n" NOR);

        do_loving(man, woman, 10 + random(8));
        do_loving(woman, man, 10 + random(3));
}

void do_loving(object me, object target, int wakeup)
{
        me->set_temp("sleeped", 1);
        me->set_temp("block_msg/all", 1);
        me->disable_player(" <������>");
        me->start_call_out((: call_other, me, "do_over", me :),10);
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set_temp("last_makelove", time());
        me->add("sex/" + target->name(1), 1);
        me->add("sex/times", 1);
        if (me->query("sex/times") == 1)
                me->set("sex/first", target->name(1));
        if (me->query("gender") == "����")
        {
                me->set("gin", 20);
                me->set("kee", 50);
        }
}

void do_over(object me)
{
        if (! me || ! me->query_temp("sleeped"))
                return;

        me->delete_temp("sleeped");
	if (living(me)) return;

        me->enable_player();
        me->set_temp("block_msg/all", 0);
        me->delete("no_get");
        me->delete("no_get_from");
        message_vision("\n$N������һ�£��������������۾������ѹ�����\n",
                       me);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : makelove <id>
 
����������ָ������ϲ���������������Ҫ�󣬵�ȻҪ�ڰ�ȫ�ĵ�
��������Է�����������no_tell ��ѡ�����޷�������Ҫ��
�����Ժ�Ἣ��������з��ľ�������

HELP );
        return 1;
}
