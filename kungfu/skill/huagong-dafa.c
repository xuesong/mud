// huagong-dafa.c ������
// Modified by rcwiz 2003

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
    return force == "guixi-gong";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("huagong-dafa", 1);
        return lvl * lvl * 15 * 20 / 100 / 200;
}

int valid_learn(object me)
{
        if (me->query("character") == "��������")
                return notify_fail("�����а��룺��Ϊ�˹������䣬����ѧϰ���ֺ����书��\n");

        if (me->query("character") == "������")
                return notify_fail("�����а��룺����Ȼ����ǫǫ���ӣ����������˲��������书ѧ�����ã�\n");

        if (me->query("con") < 30)
                return notify_fail("��������ת��һ����������ʱ�����������ͣ�\n");

        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");

        if ((int)me->query_skill("poison", 1) < 120)
                return notify_fail("��Ļ�����������㣬����ѧ�����󷨡�\n");

        if (me->query("gender") == "����" && (int)me->query_skill("huagong-dafa", 1) > 99)
                return notify_fail("���޸����ԣ���������������������Ļ����󷨡�\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("huagong-dafa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ�������������Ļ����󷨡�\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("huagong-dafa", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ�������������Ļ����󷨡�\n");

        return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int jiali;
		int lvl;

        if ((int) me->query_skill("huagong-dafa", 1) < 80 ||
            ! living(me))
                return;

        if ((jiali = ob->query("jiali")) < 1)
                return;
		lvl = me->query_skill("huagong-dafa", 1);
        ap = ob->query_skill("force") + ob->query_skill("dodge");
        dp = me->query_skill("force") + me->query_skill("dodge");
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage ]);
				
				if (ob->query("neili") > jiali)
						ob->add("neili", -jiali);
				
				switch (random(3))
                {
                case 0:
                        result += ([ "msg" : HIM "$N" HIM "ֻ��������ԴԴ��к"
                                             "�����ɵô��һ����\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIM "$N" HIM "ֻ���÷�����������"
                                             "��ʯ���󺣣���֪���١�\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : HIM "$N" HIM "��ס�߶�����������"
                                             "ֻ����$n���ƺ���������\n" NOR ]);
                        break;
                }
				
				ob->affect_by("freezing",
                               ([ "level"    : jiali,
                                  "id"       : me->query("id"),
                                  "duration" : lvl / 60 + random(lvl / 30) ]));
				
                return result;
        }
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ(learn)�������������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"huagong-dafa/" + func;
}