#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);
    Persona(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email, const QString &edad);
    const QString &nombre() const;
    const QString &apellido() const;
    const QString &telefono() const;
    const QString &email() const;
    const QString &edad() const;

signals:

private:
    QString m_nombre;
    QString m_apellido;
    QString m_telefono;
    QString m_email;
    QString m_edad;
};

#endif // PERSONA_H
